//
// Created by Олександра
#include <stdio.h>

double calc_polynomial_v(double x) {
    double t = x + 1.0;
    double t2 = t * t;
    return t2 * t2 * t;
}

int main() {
    double x;

    printf("Enter x: ");

    if (scanf("%lf", &x) == 1) {
        double result = calc_polynomial_v(x);
        printf("%lf\n", result);
    } else {
        printf("Enter a number.\n");
    }
    return 0;
}