//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>


double calc_sqrt_a(unsigned n) {
    double y = 0;
    for (unsigned i = 0; i < n; ++i) {
        y = sqrt(2 + y);
    }
    return y;
}


double calc_sqrt_b(unsigned n) {
    double y = 0;
    for (unsigned i = n; i >= 1; --i) {
        y = sqrt(3 * i + y);
    }
    return y;
}

int main() {
    int choice;
    unsigned n;

    printf("Виберіть варіант:\n");
    printf("1 - Варіант а) (sqrt(2 + ...))\n");
    printf("2 - Варіант б) (sqrt(3 + sqrt(6 + ...)))\n");
    printf("Ваш вибір (1 або 2): ");
    scanf("%d", &choice);

    printf("Введіть кількість коренів (n): ");
    scanf("%u", &n);

    if (choice == 1) {
        double result = calc_sqrt_a(n);
        printf("Результат для варіанта а) = %f\n", result);
    } else if (choice == 2) {
        double result = calc_sqrt_b(n);
        printf("Результат для варіанта б) = %f\n", result);
    } else {
        printf("Помилка: вибрано неіснуючий варіант!\n");
    }

    return 0;
}