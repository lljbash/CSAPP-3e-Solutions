#include <stdio.h>
#include <assert.h>

int test_A(int x) {
    return !~x;
}

int test_B(int x) {
    return !x;
}

int test_C(int x) {
    int lsb = x & 0xff;
    return (lsb + 1) >> 8;
}

int test_D(int x) {
    int msb = (x >> (1 << (sizeof(int) - 1))) & 0xff;
    return test_B(msb);
}

int main() {
    assert(test_A(0xffffffff) == 1);
    assert(test_A(0x12345678) == 0);
    assert(test_A(0x00000000) == 0);
    assert(test_A(0xfffffffe) == 0);
    assert(test_B(0x00000000) == 1);
    assert(test_B(0xa0000000) == 0);
    assert(test_B(0xffffffff) == 0);
    assert(test_C(0xffffffff) == 1);
    assert(test_C(0x000000ff) == 1);
    assert(test_C(0xfffffffe) == 0);
    assert(test_C(0x00000000) == 0);
    assert(test_D(0x00000000) == 1);
    assert(test_D(0x000000ff) == 1);
    assert(test_D(0xffffff00) == 0);
    assert(test_D(0xfffffffe) == 0);
    printf("OK\n");
    return 0;
}
