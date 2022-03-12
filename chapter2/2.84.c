#include <stdio.h>
#include <assert.h>
#include <string.h>

unsigned f2u(float x) {
    unsigned y;
    memcpy(&y, &x, sizeof(float));
    return y;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */
    return (!(ux << 1) && !(uy << 1)) ||
           (sx && sy && ux >= uy) ||
           (sx && !sy) ||
           (!sx && !sy && ux <= uy);
}

int main() {
    assert(float_le(-0., 0.));
    assert(float_le(0., -0.));
    assert(float_le(-1.23, 2.45));
    assert(!float_le(456.44, -111.222));
    assert(float_le(777.88, 88888.99));
    assert(!float_le(234234.22, 222.2));
    assert(!float_le(-777.88, -88888.99));
    assert(float_le(-234234.22, -222.2));
    assert(float_le(777.88, 777.88));
    assert(float_le(-222.2, -222.2));
    printf("OK\n");
    return 0;
}
