//
// Created by Олександра
//
#include <stdio.h>

double Rosenbrock2d(double x, double y) {
    double term1 = (x * x) - y;
    double term2 = x - 1.0;
    return 100.0 * (term1 * term1) + (term2 * term2);
}

int main() {
    double x1 = 1.0, y1 = 1.0;
    double x2 = 0.0, y2 = 0.0;
    double x3 = 2.0, y3 = 3.0;
    printf("x = %lf, y = %lf: result = %lf\n", x1, y1, Rosenbrock2d(x1, y1));
    printf("x = %lf, y = %lf: result = %lf\n", x2, y2, Rosenbrock2d(x2, y2));
    printf("x = %lf, y = %lf: result = %lf\n", x3, y3, Rosenbrock2d(x3, y3));
    return 0;
}