//
// Created by Олександра on 15.09.2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("Input int in rad: ");

    if (scanf("%lf", &x) == 1) {
        printf("Cos %.lf equals: %.lf\n", x, cos(x));
    } else {
        printf("Error.\n");
    }

    return 0;
}