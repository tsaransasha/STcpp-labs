//
// Created by Олександра
//
#include <stdio.h>

unsigned long long subfactorial(unsigned n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    unsigned long long sub2 = 1;
    unsigned long long sub1 = 0;
    unsigned long long current = 0;

    for (unsigned i = 2; i <= n; i++) {
        current = (i - 1) * (sub1 + sub2);
        sub2 = sub1;
        sub1 = current;
    }
    return current;
}

int main() {
    unsigned n;
    printf("Enter a value for n (n < 25):[cite: 7] ");
    scanf("%u", &n);

    if (n >= 25) {
        printf("Помилка: n має бути менше 25[cite: 7]!\n");
        return 1;
    }

    printf("!%u = %llu\n", n, subfactorial(n));

    return 0;
}