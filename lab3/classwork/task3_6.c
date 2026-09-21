//
// Created by Олександра on
//
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double max_num, min_num;

    printf("Введіть три дійсних числа: ");
    scanf("%lf %lf %lf", &a, &b, &c);


    max_num = a;
    min_num = a;


    if (fabs(b) > fabs(max_num)) {
        max_num = b;
    }
    if (fabs(c) > fabs(max_num)) {
        max_num = c;
    }


    if (fabs(b) < fabs(min_num)) {
        min_num = b;
    }
    if (fabs(c) < fabs(min_num)) {
        min_num = c;
    }

    printf("Найбільше за модулем число: %.2lf\n", max_num);
    printf("Найменше за модулем число: %.2lf\n", min_num);

    return 0;
}