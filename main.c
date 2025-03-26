#include <stdint.h>

uint64_t add(uint64_t a, uint64_t b)
{
    uint64_t c = a + b;
    return c;
}

int main(void)
{
    uint64_t a = 0x1234abcd;
    uint64_t b = 0xdcba4321;
    uint64_t c = add(a, b);

    return 0;
}