#ifndef VOLUME_HEADER_H
#define VOLUME_HEADER_H

#include <stdint.h>

#define WUKS2_MAGIC "WUKS2"
#define WUKS2_VERSION 2
#define MAX_KEYS 4

typedef struct {
    char magic[5];            // "WUKS2"
    uint8_t version;          // Header version
    uint8_t key_slot_count;   // Number of key slots
    uint32_t header_size;     // Total size of header
    uint8_t reserved[3];      // Padding
} __attribute__((packed)) VolumeHeader;

int write_volume_header(const char *path);
int read_volume_header(const char *path, VolumeHeader *out);

#endif

