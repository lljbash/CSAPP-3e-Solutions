#include <stdio.h>
#include <assert.h>

const int w = sizeof(int) << 3;

int lower_one_mask(int n) {
    unsigned mask = ~0u >> (w - n);
    return (int) mask;
}

int main() {
    assert(lower_one_mask(6) == 0x3f);
    assert(lower_one_mask(17) == 0x1ffff);
    assert(lower_one_mask(1) == 0x1);
    assert(lower_one_mask(w) == ~0);
    printf("OK\n");
    return 0;
}
