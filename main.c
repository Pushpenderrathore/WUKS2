#include <stdio.h>
#include "volume_header.h"

int main() {
    const char *disk = "virtual_disk.img";
    VolumeHeader vh;

    if (write_volume_header(disk) == 0)
        printf("✅ Header written!\n");

    if (read_volume_header(disk, &vh) == 0)
        printf("✅ Header read! Magic: %s | Version: %d\n", vh.magic, vh.version);
    else
        printf("❌ Header read failed\n");

    return 0;
}

