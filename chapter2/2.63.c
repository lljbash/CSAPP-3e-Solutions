#include <stdio.h>
#include <assert.h>

int w = sizeof(int) << 3;

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    unsigned high_k_mask = ~0u << (w - 1 - k) << 1;
    unsigned xsra_high_k = xsra & high_k_mask;
    return xsra ^ xsra_high_k;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int sbit = !!(x & (1 << (w - 1)));
    int shift = w - 1 - k;
    int mask = ~((sbit << shift) - 1);
    return xsrl | mask;
}

int main() {
    int ival = 12345;
    unsigned uval = (unsigned) ival;
    int nival = -ival;
    unsigned nuval = (unsigned) nival;
    assert(srl(uval, 0) == uval >> 0);
    assert(srl(uval, 5) == uval >> 5);
    assert(srl(uval, w - 1) == uval >> (w - 1));
    assert(srl(nuval, 0) == nuval >> 0);
    assert(srl(nuval, 5) == nuval >> 5);
    assert(srl(nuval, w - 1) == nuval >> (w - 1));
    assert(sra(ival, 0) == ival >> 0);
    assert(sra(ival, 5) == ival >> 5);
    assert(sra(ival, w - 1) == ival >> (w - 1));
    assert(sra(nival, 0) == nival >> 0);
    assert(sra(nival, 5) == nival >> 5);
    assert(sra(nival, w - 1) == nival >> (w - 1));
    printf("OK\n");
    return 0;
}
