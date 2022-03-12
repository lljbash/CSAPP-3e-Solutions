#include <stdio.h>
#include <assert.h>

double eq(int Y, int k) {
    /*   (0. y y y y y y...)_2
     * = [2^(-k) + 2^(-2k) + 2^(-3k) + ...] * Y
     * = Y / (2^k - 1)
     */
    return (double) Y / ((1 << k) - 1);
}

int main() {
    printf("%f\n", eq(1, 2)); /* y = 01, 1/3 */
    printf("%f\n", eq(3, 4)); /* y = 0011, 1/5 */
    printf("%f\n", eq(5, 3)); /* y = 101 */
    printf("%f\n", eq(6, 4)); /* y = 0110 */
    printf("%f\n", eq(19, 6)); /* y = 010011 */
    printf("OK\n");
    return 0;
}
