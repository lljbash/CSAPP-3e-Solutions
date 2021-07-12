#include <stdio.h>
#include <assert.h>
#include <limits.h>

const int w = sizeof(int) << 3;

unsigned safe_shiftleft(unsigned x, int k) {
    int is_nonzero = k != 0;
    return x << is_nonzero << (k - is_nonzero);
}

unsigned generate_A(int k) {
    return safe_shiftleft(0u - 1u, k);
}

unsigned generate_B(int k, int j) {
    return safe_shiftleft(safe_shiftleft(1u, k) - 1, j);
}

void print_binary(unsigned x) {
    for (int i = w - 1; i >= 0; --i) {
        putc(x & (1 << i) ? '1' : '0', stdout);
    }
    putc('\n', stdout);
}

int main() {
    print_binary(generate_A(0));
    print_binary(generate_A(5));
    print_binary(generate_A(w));
    print_binary(generate_B(3, 4));
    print_binary(generate_B(w, 0));
    print_binary(generate_B(0, w));
    printf("OK\n");
    return 0;
}
