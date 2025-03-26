#ifndef __CPU_H__
#define __CPU_H__

#include "cpu/reg.h"

typedef struct CPU {
    Reg regs[REG_CNT];
} CPU;

#endif /* __CPU_H__ */
