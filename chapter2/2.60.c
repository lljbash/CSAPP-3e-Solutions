#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    return x & ~(0xFFu << (i << 3)) | (b << (i << 3));
}

int main() {
    unsigned x = replace_byte(0x12345678, 2, 0xAB);
    unsigned y = replace_byte(0x12345678, 0, 0xAB);
    printf("%X\n", x);
    printf("%X\n", y);
    assert(x == 0x12AB5678);
    assert(y == 0x123456AB);
    return 0;
}
