#include <inttypes.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t bit;
    for (int i = 0; i < 32; i += 1) {
        bit = (n >> (31 - i)) & 1;
        res = res | (bit << i);
    }
    return res;
}
