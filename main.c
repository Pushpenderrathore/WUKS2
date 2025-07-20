#include <stdio.h>
#include <string.h>
#include "src/include/volume_header.h"

int main() {
    FILE *disk = fopen("virtual_disk.img", "wb+");
    if (!disk) {
        perror("Disk creation failed");
        return 1;
    }

    WUKS2Header hdr;
    memcpy(hdr.magic, WUKS2_MAGIC, 5);
    hdr.version = 1;
    hdr.cipher = 1;  // AES
    for (int i = 0; i < MAX_KEYSLOTS; i++)
        hdr.keyslots[i] = 512 * (i + 1);  // Arbitrary

    if (write_header(disk, &hdr) == 0)
        printf("Header written successfully!\n");
    else
        printf("Failed to write header\n");

    // Read back for verification
    WUKS2Header read_back;
    if (read_header(disk, &read_back) == 0) {
        printf("Header read successfully! Magic: %.5s\n", read_back.magic);
    } else {
        printf("Failed to read header\n");
    }

    fclose(disk);
    return 0;
}
