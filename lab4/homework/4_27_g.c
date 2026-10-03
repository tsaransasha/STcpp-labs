//
// Created by Олександра on 03.10.2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    double eps;
    printf("Введіть точність epsilon (> 0): ");
    scanf("%lf", &eps);

    double pi = 0.0;
    double term;
    int k = 0;

    do {


        double sign = (k % 2 == 0) ? 1.0 : -1.0;


        double pow4 = pow(4.0, k);


        double bracket = (2.0 / (4.0 * k + 1.0)) +
                         (2.0 / (4.0 * k + 2.0)) +
                         (1.0 / (4.0 * k + 3.0));

        term = sign * bracket / pow4;
        pi += term;
        k++;

    } while (fabs(term) >= eps);

    printf("Обчислене значення pi = %.10f\n", pi);
    printf("Кількість ітерацій: %d\n", k);

    return 0;
}