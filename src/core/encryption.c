#include "encryption.h" 
#include <openssl/evp.h> 
#include <string.h> 

int encrypt_sector(const uint8_t *plaintext, uint8_t *ciphertext, size_t len, const uint8_t *key, const uint8_t *iv) {
     EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
     int outlen;

     if (!ctx)
         return -1;

     if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_xts(), NULL, key, iv)) {
         EVP_CIPHER_CTX_free(ctx);
         return -2;
     }

     if (!EVP_EncryptUpdate(ctx, ciphertext, &outlen, plaintext, len)) {
         EVP_CIPHER_CTX_free(ctx);
         return -3;
     }

     EVP_CIPHER_CTX_free(ctx);
     return 0;
 }

int decrypt_sector(const uint8_t *ciphertext, uint8_t *plaintext, size_t len, const uint8_t *key, const uint8_t *iv) {
     EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
     int outlen;

     if (!ctx)
         return -1;

     if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_xts(), NULL, key, iv)) {
         EVP_CIPHER_CTX_free(ctx);
         return -2;
     }

     if (!EVP_DecryptUpdate(ctx, plaintext, &outlen, ciphertext, len)) {
         EVP_CIPHER_CTX_free(ctx);
         return -3;
     }

     EVP_CIPHER_CTX_free(ctx);
     return 0;
 } 
