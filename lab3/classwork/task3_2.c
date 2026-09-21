//
// Created by Олександра
//
#include <stdio.h>

void print_permutations(unsigned n) {
    unsigned d1 = n / 100;
    unsigned d2 = (n / 10) % 10;
    unsigned d3 = n % 10;

    if (d1 != d2 && d2 != d3 && d1 != d3) {
        printf("All permutations:\n");
        printf("%u%u%u\n", d1, d2, d3);
        printf("%u%u%u\n", d1, d3, d2);
        printf("%u%u%u\n", d2, d1, d3);
        printf("%u%u%u\n", d2, d3, d1);
        printf("%u%u%u\n", d3, d1, d2);
        printf("%u%u%u\n", d3, d2, d1);
    } else {
        printf("The digits are not all distinct.\n");
    }
}

int main() {
    unsigned n;
    printf("Enter a three-digit number: ");
    scanf("%u", &n);

    print_permutations(n);

    return 0;
}