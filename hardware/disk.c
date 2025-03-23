#include "disk.h"
#include <string.h>

/*
 * Read sectors from disk
 */
int disk_read(int start_sec, char *buf, int cnt)
{
    if ((start_sec < 0) || (start_sec + cnt * SECTOR_SZ) > DISK_SZ)
        return -1;

    int offset = start_sec * SECTOR_SZ;
    memcpy(buf, disk + offset, cnt * SECTOR_SZ);
    return 0;
}