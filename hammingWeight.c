#include <stdint.h>

int hammingWeight(uint32_t n) {
    uint32_t ones = 0;
    while (n) {
        if (n & 1) {
            ones += 1;
        }
        n >>= 1;
    }
    return ones;
}