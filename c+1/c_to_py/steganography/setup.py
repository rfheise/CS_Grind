from distutils.core import setup, Extension


module = Extension('stegano', sources = ['python_link.cpp','ImageData.cpp'])

setup(name = "stegano", version = '1.0', description = "LSB steganography", ext_modules = [module])