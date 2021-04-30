#ifndef __DATA_H_
#define __DATA_H_
#include <string>
#include <cstdint>
#include <fstream>
using namespace std;
typedef uint8_t byte;

class ImageData {
    private:
        ifstream image;
        int filesize;
        ofstream out;
        char *buffer;
        const int buffer_size = 10000;
        void addMetaData(int meta);
        char readCharacter();
        void writeCharacter(char c);
        int readMetaData();
        int head_size;
    public:
        void encrypt(string message);
        void decrypt();
        ImageData(string file);
        void encrypt(ifstream &fp);
        ~ImageData();
};

struct RGB {
    byte red;
    byte blue;
    byte green;
};



#endif