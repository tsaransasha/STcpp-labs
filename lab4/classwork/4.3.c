//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>


double calc_polynomial_a(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += pow(x, i);
    }
    return sum;
}


double calc_polynomial_b(double x, double y_val, int n) {
    double sum = 1.0;
    for (int k = 1; k <= n; k++) {
        sum += pow(x, 2 * k) * pow(y_val, k);
    }
    return sum;
}

int main() {

    double x_a = 2.0;
    int n_a = 3;
    printf("Result a): %lf\n", calc_polynomial_a(x_a, n_a));


    double x_b = 1.0;
    double y_b = 2.0;
    int n_b = 4;
    printf("Result b): %lf\n", calc_polynomial_b(x_b, y_b, n_b));

    return 0;
}