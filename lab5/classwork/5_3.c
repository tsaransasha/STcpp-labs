#include <stdio.h>


int get_collatz_steps(unsigned long long n) {
    int steps = 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    unsigned long long n;
    printf("Введіть натуральне число n: ");
    if (scanf("%llu", &n) != 1 || n == 0) {
        printf("Помилка введення.\n");
        return 1;
    }


    printf("\nПослідовність {a_i} для n = %llu:\n%llu", n, n);
    unsigned long long current = n;
    while (current > 1) {
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
        printf(" -> %llu", current);
    }
    printf("\nКількість кроків для досягнення одиниці: %d\n\n", get_collatz_steps(n));


    unsigned long long max_n = 1;
    int max_steps = 0;

    for (unsigned long long i = 1; i < 1000; i++) {
        int steps = get_collatz_steps(i);
        if (steps > max_steps) {
            max_steps = steps;
            max_n = i;
        }
    }

    printf("=== Аналіз для n < 1000 ===\n");
    printf("Число n, якому потрібна максимальна кількість кроків: %llu\n", max_n);
    printf("Максимальна кількість кроків: %d\n", max_steps);

    return 0;
}