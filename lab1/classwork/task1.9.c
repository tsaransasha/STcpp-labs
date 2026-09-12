//
// Created by Олександра on 09.09.2026.
//
#include <stdio.h>

int main() {
    double x, y;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);

    double avg = (x + y) / 2.0;
    double harmonic = 2.0 / ((1.0 / x) + (1.0 / y));

    printf("Середнє арифметичне:\n Десяткове: %f\n Наукове: %e\n\n", avg, avg);
    printf("Середнє гармонічне:\n Десяткове: %f\n Наукове: %e\n", harmonic, harmonic);

}