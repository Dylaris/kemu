#ifndef __REG_H__
#define __REG_H__

#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

enum REG {
    RAX, RBX, RCX, RDX,
    RSI, RDI, RBP, RSP,
    RIP, REG_CNT
};

typedef union Reg {
    u64 x;                  /* rax */
    u32 e;                  /* eax */
    u16 r;                  /* ax */
    struct { u8 l, h; };    /* al, ah */
} Reg;

#endif /* __REG_H__ */
