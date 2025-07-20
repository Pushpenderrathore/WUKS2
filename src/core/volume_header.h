#ifndef VOLUME_HEADER_H
#define VOLUME_HEADER_H

#include <stdint.h>

#define WUKS2_MAGIC "WUKS2HDR"
#define WUKS2_VERSION 1

typedef struct {
    char magic[8];           // WUKS2HDR
    uint32_t version;        // 1
    uint8_t salt[32];        // For key derivation
    uint8_t encrypted_key[64]; // Key blob encrypted with user passphrase
} volume_header_t;

#endif
