#include "../include/encryption.h"
#include <stdio.h>
#include <string.h>

int main() {
    const char *password = "secure123";
    uint8_t salt[32] = {0}; // Random in real use
    uint8_t key[64] = {0};

    if (derive_key_from_passphrase(password, salt, 32, key, 64, 100000) == 0)
        printf("✅ Key derivation succeeded\n");
    else
        printf("❌ Key derivation failed\n");

    return 0;
}
