#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

const int w = sizeof(int) << 3;

int mul_17(int x) {
    return (x << 4) + x;
}

int mul_n7(int x) {
    return x - (x << 3);
}

int mul_60(int x) {
    return (x << 6) - (x << 2);
}

int mul_n112(int x) {
    return (x << 4) - (x << 7);
}

void test_one(int x, int mul, int (*mulf)(int)) {
    assert(x * mul == mulf(x));
}

void test(int mul, int (*mulf)(int)) {
    test_one(0, mul, mulf);
    test_one(123, mul, mulf);
    test_one(-456, mul, mulf);
}

int main() {
    test(17, mul_17);
    test(-7, mul_n7);
    test(60, mul_60);
    test(-112, mul_n112);
    printf("OK\n");
    return 0;
}
