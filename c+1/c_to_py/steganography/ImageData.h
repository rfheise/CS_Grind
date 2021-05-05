#ifndef __DATA_H_
#define __DATA_H_
#include <string>
#include <cstdint>
#include <fstream>
using namespace std;

class ImageData {
    private:
        //image you are reading from
        ifstream image;
        int filesize;
        //file you are writing to
        ofstream out;
        //buffer
        char *buffer;
        //buffer size
        const int buffer_size = 1000;
        //method for adding meta data to bmp
        void addMetaData(int meta);
        //method for reading characters from encrypted bmp
        char readCharacter();
        //method for writing encrypted characters to bmp
        void writeCharacter(char c);
        //method for reading in meta data from encrypted bmp
        int readMetaData();
        //size of bmp 2nd chunk of meta data
        int head_size;
    public:
        //string encryption method
        void encrypt(string message,string outfile);
        //stdio decryption method
        void decrypt();
        //file decryption method
        void decrypt(string outfile);
        //constructor
        ImageData(string file);
        const char * decrypt_string();
        //file encryption method
        void encrypt(ifstream &fp, string outfile);
        //destructor
        ~ImageData();
};



#endif