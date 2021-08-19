#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <openssl/des.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <cstring>
#include <iostream>
using namespace std;
int main(void) {
    EVP_PKEY_CTX *ctx;
    EVP_PKEY *pkey = NULL;

    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    if (!ctx){
        /* Error occurred */
        return 4;
    }
       
    if (EVP_PKEY_keygen_init(ctx) <= 0) {
        /* Error */
        return 1;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 512) <= 0){
        /* Error */
        return 2;
    }
     /* Generate key */
    if (EVP_PKEY_keygen(ctx, &pkey) <= 0) {
        /* Error */
        return 3;
    }
    
    EVP_PKEY_CTX_free(ctx);
    ctx = EVP_PKEY_CTX_new(pkey, NULL);
    if (!ctx) {
        return 9;
    }

        /* Error occurred */
    if (EVP_PKEY_encrypt_init(ctx) <= 0) {
        return 10;
    }
        /* Error */
    // if (EVP_PKEY_CTX_set_rsa_padding(ctx, 0) <= 0) {
    //         return 11;
    // }


    const char *in = "epic";
    unsigned char *out;
    size_t outlen = 0;
    /* Determine buffer length */
    if (EVP_PKEY_encrypt(ctx, NULL, &outlen, (unsigned char *)in, 5) <= 0) {
        /* Error */
        return 5;
    }
        

    out = new unsigned char[outlen];

    if (!out) {
        /* malloc failure */
        return 6;
    }

    if (EVP_PKEY_encrypt(ctx, out, &outlen, (unsigned char *)in, 5) <= 0) {
        /* Error */
        return 7;
    }
    EVP_PKEY_CTX_free(ctx);
    ctx = EVP_PKEY_CTX_new(pkey, NULL);
     if (!ctx) {
         return 8;
     }
     /* Error occurred */
    if (EVP_PKEY_decrypt_init(ctx) <= 0)    {
        return 15;
    }
    size_t inlen;
    if (EVP_PKEY_decrypt(ctx, NULL, &inlen, out, outlen) <= 0) {
        return 20;
    }
    in = (char *)OPENSSL_malloc(inlen);
    if (EVP_PKEY_decrypt(ctx, (unsigned char *)in, &inlen, out, outlen) <= 0) {
        return 22;
    }
    unsigned char *outDer = nullptr;
    int outDerlen = i2d_PublicKey(pkey, &outDer);
    if (outDerlen <= 0 || outDer == nullptr) {
        return 25;
    }
    cout << outDerlen << endl;
    for(int i = 0; i < outDerlen; i++) {
        cout << hex << (outDer[i] & 0xff);
        if (i != outDerlen - 1) {
            cout << ":";
        }
    }
    cout << endl;
    BIO *outbio = BIO_new_fp(stdout,0);
    EVP_PKEY_print_public(outbio,pkey,0,nullptr);
    BIO_free(outbio);
    OPENSSL_free((void *) in);
    delete[] out;
    OPENSSL_free((void *) outDer);
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(ctx);
 
    // EVP_PKEY_print_private(out,pkey,0,nullptr);
    
}
