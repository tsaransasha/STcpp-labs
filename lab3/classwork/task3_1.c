//
// Created by Олександра
//
#include <stdio.h>

void solve_digits(unsigned n) {
    unsigned hundreds = n / 100;
    unsigned tens = (n / 10) % 10;
    unsigned units = n % 10;

    unsigned sum = hundreds + tens + units;
    unsigned reversed = units * 100 + tens * 10 + hundreds;

    printf("a): %u, %u, %u\n", hundreds, tens, units);
    printf("b): %u\n", sum);
    printf("v): %u\n", reversed);
}

int main() {
    unsigned n;
    printf("Enter a three-digit number: ");
    scanf("%u", &n);

    solve_digits(n);

    return 0;
}