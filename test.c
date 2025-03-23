#include "cpu.h"
#include "isa.h"
#include "disk.h"
#include "mem.h"
#include "misc.h"
#include <string.h>
#include <stdio.h>

cpu_t cpu;
unsigned char disk[DISK_SZ];
unsigned char mem[MEM_SZ];

int main(void)
{
    JMP(0x07c0, 0);
    puts("jmp to 0x07c00\n");

    LIDTR(0, 0);
    puts("load idtr\n");

    sd_t sd = {0};
    sd.base = 0;
    sd.limit = 0;
    sd.attr = 0;
    u64 sd_c = SD_CAST(sd);
    memcpy(mem + 0x7c00 + 8 * 0, &sd_c, 8);
    printf("setup sd 0: 0x%016lX\n", sd_c);

    sd.base = 0;
    sd.limit = 2047;
    sd.attr = SDA_MASK_S | SDA_MASK_G | (0xa & SDA_MASK_TYPE) | SDA_MASK_BD | SDA_MASK_P;
    sd_c = SD_CAST(sd);
    memcpy(mem + 0x7c00 + 8 * 1, &sd_c, 8);
    printf("setup sd 1: 0x%016lX\n", sd_c);

    sd.base = 0;
    sd.limit = 2047;
    sd.attr = SDA_MASK_S | SDA_MASK_G | (2 & SDA_MASK_TYPE) | SDA_MASK_BD | SDA_MASK_P;
    sd_c = SD_CAST(sd);
    memcpy(mem + 0x7c00 + 8 * 2, &sd_c, 8);
    printf("setup sd 2: 0x%016lX\n", sd_c);

    LGDTR(0x7c00, 0x7ff);
    puts("load gdtr\n");

    cpu.cregs[CR0] |= CR0_MASK_PE;
    cpu.mode = PROTECT;
    puts("switch to protect mode\n");

    return 0;
}