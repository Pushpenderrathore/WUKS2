#include "../include/encryption.h" 
#include <stdio.h> 
#include <string.h> 

int main() {
     uint8_t key[64] = {0}; // 512 bits for AES-XTS (2 x 256)
     uint8_t iv[16] = {0};  // 128-bit IV (usually sector number)
     uint8_t plaintext[512] = "WUKS2 Test Data";
     uint8_t ciphertext[512] = {0};
     uint8_t decrypted[512] = {0};

     encrypt_sector(plaintext, ciphertext, 512, key, iv);
     decrypt_sector(ciphertext, decrypted, 512, key, iv);

     if (memcmp(plaintext, decrypted, 512) == 0)
         printf("✅ AES-XTS encryption/decryption test passed\n");
     else
         printf("❌ AES-XTS encryption/decryption test failed\n");

     return 0;
 } 
