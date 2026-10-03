#include <stdio.h>

double calculate_fraction_a(double b, int n) {
    double res = b;
    for (int i = 1; i < n; i++) {
        res = b + 1.0 / res;
    }
    return res;
}
double calculate_fraction_b(int n) {
    double b_prev = 4 * n + 2;
    for (int k = 1; k <= n; k++) {
        b_prev = 4 * (n - k) + 2 + 1.0 / b_prev;
    }
    return b_prev;
}

double calculate_fraction_c(int n) {
    double res = 2.0;
    for (int i = 2 * n - 1; i >= 1; i--) {
        if (i % 2 == 1) {
            res = 1.0 + 1.0 / res;
        } else {
            res = 2.0 + 1.0 / res;
        }
    }
    return res;
}

int main() {
    int choice;
    printf("Виберіть пункт ланцюгового дробу (а, б або в)[cite: 13]:\n");
    printf("1 - Пункт а) (значення b_n)\n");
    printf("2 - Пункт б) (значення ламбда_n через рекурентне співвідношення)\n");
    printf("3 - Пункт в) (значення x_2n)\n");
    printf("Ваш вибір (1-3): ");

    if (scanf("%d", &choice) != 1) {
        printf("Помилка введення.\n");
        return -1;
    }

    if (choice == 1) {
        double b;
        int n;
        printf("Введіть базове число b: ");
        scanf("%lf", &b);
        printf("Введіть кількість поверхів n: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("n має бути більшим за 0.\n");
            return -1;
        }
        double result = calculate_fraction_a(b, n);
        printf("Результат для пункту а) = %.10lf\n", result);
    }
    else if (choice == 2) {
        int n;
        printf("Введіть n: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("n має бути більшим за 0.\n");
            return -1;
        }
        double result = calculate_fraction_b(n);
        printf("Результат для пункту б) = %.10lf\n", result);
    }
    else if (choice == 3) {
        int n;
        printf("Enter n: ");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Wrong input.\n");
            return -1;
        }
        double x = calculate_fraction_c(n);
        printf("x_%d = %.10lf\n", 2 * n, x);
    }
    else {
        printf("Невірний вибір пункту.\n");
    }

    return 0;
}