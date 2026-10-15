#include <stdio.h>
#include <stdlib.h>

double sum_culc(int n) {
    double a1, a2, a, b1, b2, b, sum, pow;

    if (n <= 0) return 0.0;

    a1 = 0.0;
    a2 = 1.0;
    b1 = 1.0;
    b2 = 0.0;

    pow = 2.0;
    sum = pow / (a1 + b1);

    if (n == 1) return sum;

    pow = pow * 2.0;
    sum = sum + pow / (a2 + b2);

    if (n == 2) return sum;

    for (int k = 3; k <= n; k++) {
        a = a2 / k + a1 * b2;
        b = b2 + a2;
        pow = pow * 2.0;

        sum = sum + pow / (a + b);

        a1 = a2;
        a2 = a;
        b1 = b2;
        b2 = b;
    }

    return sum;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wrong input.\n");
        return EXIT_FAILURE;
    }

    double result = sum_culc(n);
    printf("Result = %lf\n", result);

    return EXIT_SUCCESS;
}