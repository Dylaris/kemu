#ifndef ISA_H
#define ISA_H

#include "cpu.h"

#define JMP(base, off) do { \
        cpu.sregs[CS] = base; \
        if (cpu.mode == REAL) \
            cpu.regs[IP].r = off; \
        else \
            cpu.regs[IP].e = off; \
    } while (0)

#define MOVE(dst, src) ((dst) = (src))

#define LGDTR(b, l) do { \
        cpu.gdtr.base = (b); \
        cpu.gdtr.limit = (l); \
    } while (0)

#define LIDTR(b, l) do { \
        cpu.idtr.base = (b); \
        cpu.idtr.limit = (l); \
    } while (0)

#define LLDTR(s) do { cpu.ldtr.selector = (s) } while (0)

#define LTR(s) do { cpu.tr.selector = (s) } while (0)

#endif /* ISA_H */