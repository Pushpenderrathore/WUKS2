#include <stdio.h>
#include <string.h>
#include "volume_header.h"

int write_volume_header(const char *path) {
    VolumeHeader header;
    memcpy(header.magic, WUKS2_MAGIC, 5);
    header.version = WUKS2_VERSION;
    header.key_slot_count = 0;
    header.header_size = sizeof(VolumeHeader);
    memset(header.reserved, 0, sizeof(header.reserved));

    FILE *f = fopen(path, "wb");
    if (!f) return -1;
    fwrite(&header, sizeof(VolumeHeader), 1, f);
    fclose(f);
    return 0;
}

int read_volume_header(const char *path, VolumeHeader *out) {
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    fread(out, sizeof(VolumeHeader), 1, f);
    fclose(f);

    if (memcmp(out->magic, WUKS2_MAGIC, 5) != 0) return -2;
    return 0;
}
