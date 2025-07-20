#include "volume_header.h"
#include <string.h>

int write_header(FILE *device, const WUKS2Header *hdr) {
    fseek(device, 0, SEEK_SET);
    return fwrite(hdr, sizeof(WUKS2Header), 1, device) == 1 ? 0 : -1;
}

int read_header(FILE *device, WUKS2Header *hdr_out) {
    fseek(device, 0, SEEK_SET);
    return fread(hdr_out, sizeof(WUKS2Header), 1, device) == 1 ? 0 : -1;
}
