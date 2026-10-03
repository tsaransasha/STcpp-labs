//
// Created by Олександра on 03.10.2026.
//
#include <stdio.h>

int main() {
    double x;
    int n;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть кількість елементів n (k від 0 до n): ");
    scanf("%d", &n);

    double current_term = 1.0;


    printf("\nЕлементи послідовності:\n");
    for (int k = 0; k <= n; k++) {
        if (k == 0) {
            current_term = 1.0;
        } else {

            current_term = current_term * x / k;
        }

        printf("x_%d = %lf\n", k, current_term);
    }

    return 0;
}