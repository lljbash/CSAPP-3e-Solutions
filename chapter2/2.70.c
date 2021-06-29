#include <stdio.h>
#include <assert.h>

int fit_bits(int x, int n) {
    int t = x >> (n - 1);
    return !(t && (t + 1));
}

int main() {
    for (int i = -65536; i <= 65536; ++i) {
        assert(fit_bits(i, 1) == (i >= -1 && i < 1));
        assert(fit_bits(i, 16) == (i >= -32768 && i < 32768));
    }
    printf("OK\n");
    return 0;
}
