from stegano import encrypt_file, decrypt_to_file
from PIL import Image

def encrypt_png(filename,string,outfile):
    e = Image.open(filename)
    e.save("out.bmp")
    encrypt_file("out.bmp", "math.png", "temp.bmp")
    e = Image.open("temp.bmp")
    e.save(outfile)
def decrypt_png(filename):
    e = Image.open(filename)
    e.save("outer.bmp")
    decrypt_to_file("outer.bmp","out.png")
encrypt_png("math.png", "cool math bro", "mather.png")
decrypt_png("mather.png")
