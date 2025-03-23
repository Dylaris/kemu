#ifndef DISK_H
#define DISK_H

#define SECTOR_SZ 512
#define DISK_SZ   (SECTOR_SZ * 20)

extern unsigned char disk[DISK_SZ];

int disk_read(int start_sec, char *buf, int cnt);

#endif /* DISK_H */