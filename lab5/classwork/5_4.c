#include <stdio.h>

int main() {
    unsigned n;
    printf("Enter a value for n: ");
    scanf("%u", &n);

    double P = 1.0;
    double fact = 1.0;

    for (unsigned i = 1; i <= n; i++) {
        fact *= i;
        double a_i = 1.0 + (1.0 / fact);
        P *= a_i;
    }

    printf("Result P_%u = %lf\n", n, P);
    return 0;
}