//
// Created by Олександра
//
#include <stdio.h>

int main() {
    double m, v, e_k;

    printf("Обчислення кінетичної енергії\n");


    printf("Введіть масу тіла m (у кілограмах): ");
    if (scanf("%lf", &m) != 1 || m < 0) {
        printf("Помилка: Маса має бути додатня\n");
        return 1;
    }

    printf("Введіть швидкість тіла v (m/c): ");
    if (scanf("%lf", &v) != 1) {
        printf("Помилка: Неправильний формат введення швидкості!\n");
        return 1;
    }
    e_k = (m * v * v) / 2.0;
    printf("\nРезультат:\n");
    printf("Кінетична енергія тіла становить: %.2f Дж \n", e_k);

    return 0;
}