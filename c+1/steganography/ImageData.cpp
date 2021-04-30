#include "ImageData.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
using namespace std;
typedef uint8_t byte;

ImageData::ImageData(string filename) {
    image = ifstream(filename, ios::binary);
    if(!image.is_open()) {
        image.close();
        cout << "Error opening file" << endl;
        throw 1;
    }
    image.seekg(14, ios::beg);
    head_size = 0;
    image.read(reinterpret_cast<char *>(&head_size), 4);
    int height = 0;
    int width = 0;
    image.read(reinterpret_cast<char *>(&height), 4);
    image.read(reinterpret_cast<char *>(&width), 4);
    image.seekg(14+head_size, ios::beg);
    filesize = height * width * 3;
    buffer = new char[buffer_size];

}
void ImageData::addMetaData(int meta) {
    image.seekg(0, ios::beg);
    image.read(buffer, head_size + 14);
    out.write(buffer, head_size + 14);
    char *temp = (char *)&meta;
    for (unsigned int i = 0; i < sizeof(int); i++) {
        writeCharacter(temp[i]);
    }
    for (int i = 0; i < 4; i++) {
        cout << std::hex <<(unsigned int)temp[i] << endl;
    }
}
void ImageData::writeCharacter(char c) {
    //mask to get last two bits
    char arr[4] = {3,3,3,3};
    for (int i = 0; i < 4; i++) {
        //isolate last two bits
        arr[i] &= c;
        //shift c by 2 to get next two bits
        c >>= 2;
    }
    image.read(buffer, 4);
    for (int i =0; i < 4; i++) {
        buffer[i] &= 0xfc;
        buffer[i] |= arr[i];
    }
    out.write(buffer, 4);
}
void ImageData::encrypt(string message) {
    int allowed = (filesize - 16)/4;
    if (message.size() > (unsigned int) allowed) {
        cout << "message too large" << endl;
        throw 2;
    }
    int length = message.size();
    out = ofstream("out.bmp",ios::binary);
    addMetaData(length);
    for (int i = 0; i < length; i++) {
        writeCharacter(message[i]);
    }
    out << image.rdbuf();

}
int getSize(ifstream &fp) {
    int cur = fp.tellg();
    fp.seekg(0,ios::beg);
    int beg = fp.tellg();
    fp.seekg(0,ios::end);
    int end = fp.tellg();
    fp.seekg(cur, ios::beg);
    return end - beg;
}
void ImageData::encrypt(ifstream &fp) {
    int allowed = (filesize - 16)/4;
    cout << allowed << endl;
    unsigned int size = getSize(fp);
    cout << size << endl;
    if (size > (unsigned int) allowed) {
        cout << "message too large" << endl;
        throw 2;
    }
    fp.seekg(0,ios::beg);
    out = ofstream("out.bmp",ios::binary);
    addMetaData(size);
    char c;
    for (unsigned int i = 0; i < size; i++) {
        fp.read(&c, 1);
        writeCharacter(c);
    }
    out << image.rdbuf();
}
char ImageData::readCharacter() {
    char x = 0;
    image.read(buffer, 4);
    for (int i = 3; i >= 0; i--) {
        x <<= 2;
        x |= (buffer[i] & 3); 
    }
    return x;
}
int ImageData::readMetaData() {
    char meta[4];
    for (int i = 0; i < 4; i++) {
        meta[i] = readCharacter();
    }
    // for (int i = 0; i < 4; i++) {
    //     cout << std::hex <<(unsigned int)meta[i] << endl;
    // }
    return *((int *)(meta));

}
void ImageData::decrypt() {
    cout << "here" << endl;
    int length = readMetaData();
    // int length = 55359;
    cout << length << endl;
    cout << "here" << endl;
    for (int i = 0; i < length; i++) {
        cout << readCharacter();
    }
    cout << endl;
}
ImageData::~ImageData() {
    image.close();
    out.close();
    delete[] buffer;
}