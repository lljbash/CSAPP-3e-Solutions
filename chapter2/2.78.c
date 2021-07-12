#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int divide_power2(int x, int k) {
    int is_neg = x >> (w - 1);
    int is_pos = ~is_neg;
    return (is_neg & ((x + (1 << k) - 1) >> k)) + (is_pos & (x >> k));
}

int main() {
    assert(0x1234 / (1 << 5) == divide_power2(0x1234, 5));
    assert(-0x1234 / (1 << 5) == divide_power2(-0x1234, 5));
    assert(INT_MIN / (1 << 5) == divide_power2(INT_MIN, 5));
    printf("OK\n");
    return 0;
}
