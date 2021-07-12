#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int signed_high_prod(int x, int y) {
    long long full_prod = (long long) x * y;
    long long high_prod = (full_prod >> w) & ((1ll << w) - 1);
    return (int) high_prod;
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    unsigned first = signed_high_prod(x, y);
    unsigned second = (x >> (w - 1)) * y + (y >> (w - 1)) * x;
    return first + second;
}

unsigned unsigned_high_prod_std(unsigned x, unsigned y) {
    unsigned long long full_prod = (unsigned long long) x * y;
    unsigned long long high_prod = (full_prod >> w) & ((1ull << w) - 1);
    return (unsigned) high_prod;
}

int main() {
    unsigned a = 0xabcdef01;
    unsigned b = 0x76543219;
    assert(unsigned_high_prod(a, b) == unsigned_high_prod_std(a, b));
    printf("OK\n");
    return 0;
}
