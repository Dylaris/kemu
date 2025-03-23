#ifndef MISC_H
#define MISC_H

#include <stdint.h>
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/*
 * General segment descriptor
 */
typedef struct SegDesc {
    u32 base;
    u32 limit : 20;
    u16 attr : 12;
} __attribute__((packed)) sd_t;

/*
 * Segment Descriptor Attribute Mask
 */
#define SDA_MASK_G    (1 << 11)
#define SDA_MASK_BD   (1 << 10)
#define SDA_MASK_AVL  (1 << 8)
#define SDA_MASK_P    (1 << 7)
#define SDA_MASK_DPL  (3 << 5)
#define SDA_MASK_S    (1 << 4)
#define SDA_MASK_TYPE (15 << 0)

#define SD_CAST(sd) \
    ((((u64)(sd).limit & 0x0ffff   ) << 0 ) | (((u64)(sd).limit & 0xf0000   ) << 32) | \
     (((u64)(sd).base  & 0x00ffffff) << 16) | (((u64)(sd).base  & 0xff000000) << 32) | \
     (((u64)(sd).attr  & 0x0ff     ) << 40) | (((u64)(sd).attr  & 0xf00     ) << 44))

#endif /* MISC_H */