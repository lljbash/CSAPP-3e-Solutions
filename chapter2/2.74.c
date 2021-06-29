#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int tsub_ok(int x, int y) {
    int sub = x - y;
    int pos_over = ~(x >> (w - 1)) & (y >> (w - 1)) & (sub >> (w - 1));
    int neg_over = (x >> (w - 1)) & ~(y >> (w - 1)) & ~(sub >> (w - 1));
    return ~(pos_over | neg_over) & 1;
}

int main() {
    assert(tsub_ok(0, 0));
    assert(tsub_ok(100, 200));
    assert(tsub_ok(200, 100));
    assert(tsub_ok(-1, INT_MIN));
    assert(!tsub_ok(0, INT_MIN));
    assert(!tsub_ok(INT_MAX, INT_MIN));
    assert(tsub_ok(0, INT_MAX));
    assert(tsub_ok(-1, INT_MAX));
    assert(!tsub_ok(-2, INT_MAX));
    assert(!tsub_ok(INT_MIN, INT_MAX));
    printf("OK\n");
    return 0;
}
