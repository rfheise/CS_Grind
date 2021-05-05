#include "ImageData.h"
#include "link.h"
void decrypt(char * filename) {
    ImageData x(filename);
    x.decrypt();
}