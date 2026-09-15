//
// Created by Олександра
//
#include <stdio.h>
int main() {
    double g = 6.673e-11;
    double m1 = 10.0;
    double m2 = 20.0;
    double r = 5.0;
    double F = g * (m1 * m2) / (r * r);
    printf("F=%e\n", F);
}