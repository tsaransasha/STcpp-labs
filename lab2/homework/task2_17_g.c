//
// Created by Олександра 
//
#include <stdio.h>
#include <math.h>

// Власна функція для обчислення arctg(x)
double arctg_func(double x) {
    return atan(x);
}


double arctg_derivative(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double x;

    printf("Введіть x: ");

    if (scanf("%lf", &x) == 1) {
        double val = arctg_func(x);
        double der = arctg_derivative(x);

        printf("f(x) = %lf\n", val);
        printf("f'(x) = %lf\n", der);
    } else {
        printf("Помилка: введіть число.\n");
    }

    return 0;
}