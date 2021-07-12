#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int divide_power2(int x, int k) {
    int is_neg = x >> (w - 1);
    int is_pos = ~is_neg;
    return (is_neg & ((x + (1 << k) - 1) >> k)) + (is_pos & (x >> k));
}

int threefourths(int x) {
    int quarter = divide_power2(x, 2);
    int rem = x - (quarter << 2);
    int bias = divide_power2(rem + rem + rem, 2);
    return quarter + quarter + quarter + bias;
}

void test(int x) {
    assert((int) (x * 0.75) == threefourths(x));
}

int main() {
    test(INT_MAX);
    test(INT_MAX - 1);
    test(INT_MAX - 2);
    test(INT_MAX - 3);
    test(INT_MIN);
    test(INT_MIN + 1);
    test(INT_MIN + 2);
    test(INT_MIN + 3);
    printf("OK\n");
    return 0;
}
