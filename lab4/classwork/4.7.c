//
// Created by Олександра
//
#include <stdio.h>

double calc_taylor(double x, unsigned n) {
    double sum = 1;
    double dod = 1;
    for (unsigned i = 1; i <= n; ++i) {
        dod = dod * (x/i);
        sum += dod;
    }
    return sum;
}

int main() {
    unsigned n;
    double x;
    printf("Enter x(|x|<1): ");
    scanf("%lf", &x);

    printf("Enter n(n>=0): ");
    scanf("%u", &n);

    double result = calc_taylor(x, n);
    printf("%lf\n", result);
}