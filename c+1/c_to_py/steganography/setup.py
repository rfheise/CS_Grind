from distutils.core import setup, Extension


module = Extension('stegano', sources = ['python_link.cpp','ImageData.cpp'],
    extra_compile_args=['-std=c++11'])

setup(name = "stegano", version = '1.0', description = "LSB steganography", ext_modules = [module])