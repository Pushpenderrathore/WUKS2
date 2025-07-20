#include <openssl/evp.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

int derive_key_from_passphrase(const char *passphrase, const uint8_t *salt, size_t salt_len,
                                uint8_t *key_out, size_t key_len, int iterations) {
    if (!PKCS5_PBKDF2_HMAC(passphrase, strlen(passphrase),
                           salt, salt_len,
                           iterations,
                           EVP_sha512(),
                           key_len,
                           key_out)) {
        return -1;
    }
    return 0;
}
