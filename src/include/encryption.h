#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdint.h>
#include <stddef.h>

#define AES_BLOCK_SIZE 16

int encrypt_sector(const uint8_t *plaintext, uint8_t *ciphertext, size_t len, const uint8_t *key, const uint8_t *iv);
int decrypt_sector(const uint8_t *ciphertext, uint8_t *plaintext, size_t len, const uint8_t *key, const uint8_t *iv); 

#endif // ENCRYPTION_H
