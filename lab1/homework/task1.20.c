//
// Created by Олександра on 09.09.2026.
//
#include <stdio.h>

int main() {
    double a, b, c;
    double arithmetic_mean, harmonic_mean;

    printf("Введіть дані у форматі 'A=xxx.xxx, B=xxExxx C=xxx.xxxx':\n");
    if (scanf("A=%lf, B=%lf C=%lf", &a, &b, &c) != 3) {
        printf("Помилка: Неправильний формат введення!\n");
        return 1;
    }

    arithmetic_mean = (a + b + c) / 3.0;

    int can_calc_harmonic = 1;
    if (a == 0.0 || b == 0.0 || c == 0.0) {
        can_calc_harmonic = 0;
    } else {
        harmonic_mean = 3.0 / ((1.0 / a) + (1.0 / b) + (1.0 / c));
    }

    printf("\n--- Результати ---\n");

    printf("Середнє арифметичне:\n");
    printf("  Формат з фіксованою крапкою: %f\n", arithmetic_mean);
    printf("  Науковий формат:             %e\n", arithmetic_mean);

    if (can_calc_harmonic) {
        printf("\nСереднє гармонічне:\n");
        printf("  Формат з фіксованою крапкою: %f\n", harmonic_mean);
        printf("  Науковий формат:             %e\n", harmonic_mean);
    } else {
        printf("\nСереднє гармонічне неможливо обчислити, оскільки одне з чисел дорівнює нулю.\n");
    }

    return 0;
}