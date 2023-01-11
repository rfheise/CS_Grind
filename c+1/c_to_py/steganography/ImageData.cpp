#include "ImageData.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <sstream>
using namespace std;

ImageData::ImageData(string filename) {
    //open image for binary file io
    image.open(filename, ios::binary);
    //checks to make sure image exists
    if(!image.is_open()) {
        image.close();
        cout << "Error opening file" << endl;
        throw 1;
    }
    //skip first chunk of bmp metadata
    image.seekg(14, ios::beg);
    //read in size of head meta data
    head_size = 0;
    image.read(reinterpret_cast<char *>(&head_size), 4);
    //get image width and height in pixels
    int height = 0;
    int width = 0;
    image.read(reinterpret_cast<char *>(&height), 4);
    image.read(reinterpret_cast<char *>(&width), 4);
    //set file location to after meta data
    image.seekg(14+head_size, ios::beg);
    //save size of "usable data" in bytes
    //each pixel is 3 bytes
    filesize = height * width * 3;
    //initialize reading buffer
    buffer = new char[buffer_size];

}
//returns true if big endian else false
bool endian() {
    int i = 1;
    char * temp = (char *)(&i);
    if (temp[0]) {
        return false;
    }
    return true;
}
//adds meta data to bmp
//rn just adds size of data being stored and bool for endianess
void ImageData::addMetaData(int meta) {
    //copies inital bmp meta data to new bmp
    image.seekg(0, ios::beg);
    image.read(buffer, head_size + 14);
    out.write(buffer, head_size + 14);
    //converts length integer to an array of bytes
    char *temp = (char *)&meta;
    for (unsigned int i = 0; i < sizeof(int); i++) {
        //stores each byte in image
        writeCharacter(temp[i]);
    }
    //adds endian boolean to file
    image.read(buffer,1);
    buffer[0] &= 0xfc;
    buffer[0] |= endian();
    out.write(buffer,1);
}
void ImageData::writeCharacter(char c) {
    //mask to get last two bits
    char arr[4] = {3,3,3,3};
    for (int i = 0; i < 4; i++) {
        //isolate last two bits
        arr[i] &= c;
        //shift c by 2 to get next two bits in char
        c >>= 2;
    }
    //read in one characters worth of storage
    image.read(buffer, 4);
    for (int i =0; i < 4; i++) {
        //set last two bits of byte to image data
        //sets last two bits of byte in buffer to 0
        buffer[i] &= 0xfc;
        //sets last two bits of buffer byte to two bits in the character
        buffer[i] |= arr[i];
    }
    //writes out edited buffer to outfile
    out.write(buffer, 4);
}
//public method thta encrypts a string into bmp
void ImageData::encrypt(string message, string outfile) {
    //gets number of bytes you can store
    //since we are storing the meta data in the first 16 bits we subtract
    //it from space left
    //since we are storing data in the 2 least significant bits
    //it will take 4 bytes of the image file to store one byte of the data we want to store
    //17 is because 2 bits are allocated for boolean of endianess
    int allowed = (filesize - 17)/4;
    //if size of message is larger than allowed throw an error
    int length = message.size();
    if (length > allowed) {
        cout << "message too large" << endl;
        throw 2;
    }
    //open bitmap for writing to outfile
    out.open(outfile,ios::binary);
    //make sure file opened properly
    if (!out.is_open()) {
        cout << "Error writing to file" << endl;
        throw 3;
    }
    //add meta data to new bmp
    addMetaData(length);
    for (int i = 0; i < length; i++) {
        //write each new character to new file
        writeCharacter(message[i]);
    }
    out << image.rdbuf();

}
//gets size of a file
int getSize(ifstream &fp) {
    //stores current position
    int cur = fp.tellg();
    //gets starting position
    fp.seekg(0,ios::beg);
    int beg = fp.tellg();
    fp.seekg(0,ios::end);
    //gets ending pos
    int end = fp.tellg();
    //resets it back to current position
    fp.seekg(cur, ios::beg);
    //returns number of bytes in file
    return end - beg;
}
void ImageData::encrypt(ifstream &fp, string outfile) {
      //gets number of bytes you can store
    //since we are storing the meta data in the first 16 bits we subtract
    //it from space left
    //since we are storing data in the 2 least significant bits
    //it will take 4 bytes of the image file to store one byte of the data we want to store
    int allowed = (filesize - 17)/4;
    //gets size of data file
    unsigned int size = getSize(fp);
    //if data file is larger than what you can store throw an error
    if (size > (unsigned int) allowed) {
        cout << "message too large" << endl;
        throw 2;
    }
    //set file position to begining
    fp.seekg(0,ios::beg);
    //open output file
    out.open(outfile,ios::binary);
    if (!out.is_open()) {
        cout << "Error opening outfile" << endl;
        throw 3;
    }
    //adds meta data to file
    addMetaData(size);
    char c;
    //reads byte by byte from data file
    for (unsigned int i = 0; i < size; i++) {
        fp.read(&c, 1);
        //writes new byte to output file
        writeCharacter(c);
    }
    //after data is finished adding
    //copy rest of the image to new file
    out << image.rdbuf();
}
//reads a character from the image file
//used in decryption
char ImageData::readCharacter() {
    char x = 0;
    //reads in 4 bytes
    image.read(buffer, 4);
    for (int i = 3; i >= 0; i--) {
        //starts at last byte since data is stored "backwards"
        //right shitfs it to make room for next two bytes
        x <<= 2;
        //saves last two bits only from buffer and adds them to 
        //end of the character
        x |= (buffer[i] & 3); 
    }
    //returns character read in
    return x;
}
//reads meta data
unsigned int ImageData::readMetaData() {
    char meta[4];
    //reads in meta data by reading in first 4
    //stored bytes
    for (int i = 0; i < 4; i++) {
        meta[i] = readCharacter();
    }
    //gets endian of machine
    bool big = endian();
    image.read(buffer,1);
    //gets endian of file
    bool data_big = buffer[0] & 1;
    //if endians do not match flip integer
    if (big != data_big) {
        for (int i = 0; i < 2; i++) {
            char temp = meta[i];
            meta[i] = meta[3 - i];
            meta[3 - i] = temp;
        }
    }
    //casts 4 byte array to integer
    unsigned int size = *((int *)(meta));
    cout << size << endl;
    //determine if size of meta data is larger than useable filesize
    //if so throw an error
    //17 is for bytes used in meta data
    if (size > (unsigned int)(filesize - 17)) {
        cout << "Corrupted File" << endl;
        throw 4;
    }
    return size;

}
//decrypts data from image
void ImageData::decrypt() {
    //reads metadata
    unsigned int length = readMetaData();
    //displayes each decrypted character
    for (unsigned int i = 0; i < length; i++) {
        cout << readCharacter();
    }
    cout << endl;
}
void ImageData::decrypt(string filename) {
    //opens output file to put decrypted data in
    //opens output file
    out.open(filename);
    if (!out.is_open()) {
        cout << "Error reading data" << endl;
        throw 3;
    }
    //reads in length of data
    unsigned int length = readMetaData();
    //writes each decrypted character to file
    for (unsigned int i = 0; i < length; i++) {
        out << readCharacter();
    }
}
const char * ImageData::decrypt_string() {
    //reads in length of data
    unsigned int length = readMetaData();
    stringstream buff("");
    //writes each decrypted character to file
    for (unsigned int i = 0; i < length; i++) {
        buff << readCharacter();
    }
    //fix string stream stuff later but this should word
    //for now
    string x = buff.str();
    int len = x.size();
    char *arr = new char[len + 1];
    for (int i = 0; i < len; i++) {
        arr[i] = x[i];
    }
    arr[len] = '\0';
    return arr;
}
//image reader deconstructor
ImageData::~ImageData() {
    //closes image and output file
    image.close();
    out.close();
    //frees buffer data
    delete[] buffer;
}