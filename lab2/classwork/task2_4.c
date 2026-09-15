//
// Created by Олександра
//
#include <stdio.h>

double calc_polynomial_a(double x) {
    double x2 = x * x;
    double temp = x2 + 1.0;
    return temp * temp;
}

int main() {
    double x;

    printf("Введіть x: ");

    if (scanf("%lf", &x) == 1) {
        double result = calc_polynomial_a(x);
        printf("Результат: %lf\n", result);
    } else {
        printf("Помилка: введіть число.\n");
    }

    return 0;
}