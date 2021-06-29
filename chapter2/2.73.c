#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int saturating_add(int x, int y) {
    int sum = x + y;
    int pos_over_mask = ~(x >> (w - 1)) & ~(y >> (w - 1)) & (sum >> (w - 1));
    int neg_over_mask = (x >> (w - 1)) & (y >> (w - 1)) & ~(sum >> (w - 1));
    return (sum & ~pos_over_mask & ~neg_over_mask) + (INT_MAX & pos_over_mask) + (INT_MIN & neg_over_mask);
}

int main() {
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
    printf("OK\n");
    return 0;
}
