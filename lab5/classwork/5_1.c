#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int task1_a(double a) {
    int k = 1;
    double sum = 0.0;
    while (sum<a) {
        sum = sum + 1.0/ k;
        k++;
    }
    return k;
}
int main() {
    double a;
    printf("Enter a number: a =  ");
    scanf("%lf", &a);
    int n = task1_a(a);
    printf("First n, that makes harmonic row grater than "
           "%lf is %d", a, n);
}