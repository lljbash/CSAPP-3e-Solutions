#include <stdio.h>
#include <assert.h>

size_t f(size_t x, size_t y) {
    return (x & 0xFF) | (y & ~0xFF);
}

int main() {
    size_t x = 0x89ABCDEF;
    size_t y = 0x76543210;
    size_t z = f(x, y);
    printf("%zX\n", z);
    assert(z == 0x765432EF);
    return 0;
}
