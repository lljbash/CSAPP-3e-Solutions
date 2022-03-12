#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

int exp_A(int x, int y) {
    return (x < y) == (-x > -y);
}

int exp_B(int x, int y) {
    return ((x + y) << 4) + y - x == 17 * y + 15 * x;
}

int exp_C(int x, int y) {
    return ~x + ~y + 1 == ~(x + y);
}

int exp_D(int x, int y) {
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    return (ux - uy) == -(unsigned)(y - x);
}

int exp_E(int x, int y) {
    (void) y;
    return (x >> 2) << 2 <= x;
}

int main() {
    /*assert(!exp_A(INT_MIN, 0));*/ /* undefined behavior */
    /*assert(exp_B(x, y));*/
    /*assert(exp_C(x, y));*/
    /*assert(exp_D(x, y));*/
    /*assert(exp_E(x, y));*/
    printf("OK\n");
    return 0;
}
