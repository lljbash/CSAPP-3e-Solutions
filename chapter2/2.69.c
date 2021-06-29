#include <stdio.h>

const int w = sizeof(int) << 3;

unsigned rotate_left(unsigned x, int n) {
    return (x << n) | (x >> (w - n - 1) >> 1);
}

void test(unsigned x, int n) {
    printf("n=%d -> 0x%x\n", n, rotate_left(x, n));
}

int main() {
    unsigned x = 0x12345678u;
    printf("x = %u, w = %d\n", x, w);
    test(x, 4);
    test(x, 20);
    test(x, 0);
    test(x, w - 1);
    return 0;
}
