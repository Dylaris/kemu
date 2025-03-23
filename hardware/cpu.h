#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef union Reg {
    u32 e;      /* extend */
    u16 r;      /* regular */
    u8 l, h;    /* low/high */
} reg_t;

enum reg {
    AX, DX, CX, BX,
    BP, SI, DI, SP,
    IP, FLAGS, R_COUNT
};

/* Segment Register */
typedef u16 sreg_t;

enum sreg {
    CS, SS, DS, ES, FS, GS,
    S_COUNT
};

/*
 * EFLAGS Flags Mask
 * S: status flag
 * C: control flag
 * X: system flag
 */
#define S_MASK_CF(f)   (1 << 0)
#define S_MASK_PF(f)   (1 << 2)
#define S_MASK_AF(f)   (1 << 4)
#define S_MASK_ZF(f)   (1 << 6)
#define S_MASK_SF(f)   (1 << 7)
#define S_MASK_TF(f)   (1 << 8)
#define X_MASK_IF(f)   (1 << 9)
#define C_MASK_DF(f)   (1 << 10)
#define S_MASK_OF(f)   (1 << 11)
#define X_MASK_IOPL(f) (1 << 12)
#define X_MASK_NT(f)   (1 << 14)
#define X_MASK_RF(f)   (1 << 16)
#define X_MASK_VM(f)   (1 << 17)

/*
 * CR Flag Mask
 */
#define CR0_MASK_PE  (1 << 0)
#define CR0_MASK_MP  (1 << 1)
#define CR0_MASK_EM  (1 << 2)
#define CR0_MASK_TS  (1 << 3)
#define CR0_MASK_ET  (1 << 4)
#define CR0_MASK_NE  (1 << 5)
#define CR0_MASK_WP  (1 << 16)
#define CR0_MASK_AM  (1 << 18)
#define CR0_MASK_PG  (1 << 31)
#define CR3_MASK_PDB (~(u32)0 << 12)

enum creg {
    CR0, CR1, CR2, CR3,
    C_COUNT
};

/*
 * Running Mode
 */
#define REAL    0
#define PROTECT 1

typedef struct CPU {
    u8 mode;

    reg_t regs[R_COUNT];
    sreg_t sregs[S_COUNT];
    u32 cregs[C_COUNT];

    struct {
        u16 limit;
        u32 base;
    } gdtr, idtr;

    struct {
        u16 selector;
    } tr, ldtr;
} cpu_t;

extern cpu_t cpu;

#endif /* CPU_H */
