#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdint.h>
#include <stddef.h>

#define AES_BLOCK_SIZE 16

int encrypt_sector(const uint8_t *plaintext, uint8_t *ciphertext, size_t len, const uint8_t *key, const uint8_t *iv);
int decrypt_sector(const uint8_t *ciphertext, uint8_t *plaintext, size_t len, const uint8_t *key, const uint8_t *iv); 
int derive_key_from_passphrase(const char *passphrase, const uint8_t *salt, size_t salt_len, uint8_t *key_out, size_t key_len, int iterations);
#endif // ENCRYPTION_H
