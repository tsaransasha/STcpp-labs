//
// Created by Олександра

//
#include <stdio.h>
#include <math.h>



double calc_expression(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += i * pow(x, i);
    }
    return sum;
}

int main() {
    int n;
    double x;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть натуральне число n: ");
    scanf("%d", &n);

    double result = calc_expression(x, n);

    printf("Результат обчислення виразу: %lf\n", result);

    return 0;
}