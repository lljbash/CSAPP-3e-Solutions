#include <stdio.h>
#include <assert.h>

int odd_ones(unsigned x) {
    unsigned x31_16 = x >> 16;
    unsigned a = x31_16 ^ x;
    unsigned a15_8 = a >> 8;
    unsigned b = a15_8 ^ a;
    unsigned b7_4 = b >> 4;
    unsigned c = b7_4 ^ b;
    unsigned c3_2 = c >> 2;
    unsigned d = c3_2 ^ c;
    unsigned d1 = d >> 1;
    unsigned e = d ^ d1;
    return e & 1;
}

int main() {
    assert(odd_ones(0) == (__builtin_popcount(0) & 1));
    assert(odd_ones(1) == (__builtin_popcount(1) & 1));
    assert(odd_ones(12345) == (__builtin_popcount(12345) & 1));
    assert(odd_ones(0x12345) == (__builtin_popcount(0x12345) & 1));
    assert(odd_ones(0xffffffff) == (__builtin_popcount(0xffffffff) & 1));
    assert(odd_ones(0xfefefeff) == (__builtin_popcount(0xfefefeff) & 1));
    printf("OK\n");
    return 0;
}
