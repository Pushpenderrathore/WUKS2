#ifndef VOLUME_HEADER_H
#define VOLUME_HEADER_H

#include <stdint.h>
#include <stdio.h>

#define WUKS2_MAGIC "WUKS2"
#define MAX_KEYSLOTS 8

typedef struct {
    char magic[5];          // "WUKS2"
    uint16_t version;       // 1 for now
    uint8_t cipher;         // 1 = AES, 2 = ChaCha, etc.
    uint64_t keyslots[MAX_KEYSLOTS]; // offsets to keys in file
} WUKS2Header;

int write_header(FILE *device, const WUKS2Header *hdr);
int read_header(FILE *device, WUKS2Header *hdr_out);

#endif
