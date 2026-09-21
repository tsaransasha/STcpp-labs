//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    printf("Enter a: ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Enter b: ");
    if (scanf("%lf", &b) != 1) return 1;
    if (a <= 0 || b <= 0) {
        printf("Error.\n");
        return 1;
    }
    c = sqrt(a * a + b * b);
    printf("Hypotenuse is: %.2lf\n", c);
    return 0;
}