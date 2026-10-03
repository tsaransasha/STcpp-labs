//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>

double calc_sqrt(unsigned n) {
    double y = 0;
    for (unsigned i = 0; i < n; ++i) {
        y = sqrt(2 + y);
    }
    return y;
}

int main() {
    unsigned n;
    printf("Enter number of elements: ");
    scanf("%u", &n);

    double result = calc_sqrt(n);
    printf("Result = %f\n", result);
}