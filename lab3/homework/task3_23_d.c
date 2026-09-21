//
// Created by Олександра //
#include <stdio.h>
#include <float.h>


double sReLu(double tl, double tr, double al, double ar, double x) {
    if (x <= tl) {
        return tl + al * (x - tl);
    } else if (x > tl && x < tr) {
        return 0.0;
    } else { // x >= tr
        return tr + ar * (x - tr);
    }
}


double sReLu_derivative(double tl, double tr, double al, double ar, double x) {
    if (x < tl) {
        return al;
    } else if (x > tl && x < tr) {
        return 0.0;
    } else if (x > tr) {
        return ar;
    } else {

        return DBL_MAX;
    }
}


void run_test(double tl, double tr, double al, double ar, double x) {
    double val = sReLu(tl, tr, al, ar, x);
    double deriv = sReLu_derivative(tl, tr, al, ar, x);

    printf("x = %5.2f | sReLu(x) = %6.2f | derivative = ", x, val);

    if (deriv == DBL_MAX) {
        printf("INFINITY (DBL_MAX)\n");
    } else {
        printf("%6.2f\n", deriv);
    }
}

/////TEST/////
int main() {
    double tl = -2.0;
    double tr =  2.0;
    double al =  0.5;
    double ar =  1.5;

    printf("Testing sReLu with parameters:\n");
    printf("tl = %.2f, tr = %.2f, al = %.2f, ar = %.2f\n", tl, tr, al, ar);
    printf("----------------------------------------------------------\n");


    run_test(tl, tr, al, ar, -4.0);
    run_test(tl, tr, al, ar, -2.0);
    run_test(tl, tr, al, ar, 0.0);
    run_test(tl, tr, al, ar, 2.0);
    run_test(tl, tr, al, ar, 4.0);

    printf("\n");

    return 0;
}