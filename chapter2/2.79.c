#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int divide_power2(int x, int k) {
    int is_neg = x >> (w - 1);
    int is_pos = ~is_neg;
    return (is_neg & ((x + (1 << k) - 1) >> k)) + (is_pos & (x >> k));
}

int mul3div4(int x) {
    return divide_power2(x + x + x, 2);
}

int main() {
    assert(INT_MAX * 3 / 4 == mul3div4(INT_MAX));
    assert(INT_MIN * 3 / 4 == mul3div4(INT_MIN));
    printf("OK\n");
    return 0;
}
