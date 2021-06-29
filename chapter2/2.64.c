#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x) {
    return !!(x & 0xaaaaaaaa);
}

int main() {
    assert(any_odd_one(0x1) == 0);
    assert(any_odd_one(0x2) == 1);
    assert(any_odd_one(0x4) == 0);
    assert(any_odd_one(0x8) == 1);
    printf("OK\n");
    return 0;
}
