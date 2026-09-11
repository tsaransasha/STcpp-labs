//
// Created by Олександра

//
#include <stdio.h>
#include <math.h>
int main() {
    float x1 = 1e-4f;
    float x2 = 24.33E5f;
    float x3 = M_PI;
    float x4 = M_E;
    float x5 = sqrtf(5.0f);
    float x6 = logf(100.0f);
    printf("%.2f\n %.2f\n %.2f\n %.2f\n %.2f\n %.2f\n", x1, x2, x3, x4, x5, x6);

    double y1 = 1e-4;
    double y2 = 24.33E5;
    double y3 = M_PI;
    double y4 = M_E;
    double y5 = sqrt(5.0);
    double y6 = log(100.0);
    printf("%.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n %.2lf\n", y1, y2, y3, y4, y5, y6);

    long double z1 = 1e-4L;
    long double z2 = 24.33E5L;
    long double z3 = M_PI;
    long double z4 = M_E;
    long double z5 = sqrtl(5.0L);
    long double z6 = logl(100.0L);
    printf("%.2Lf\n %.2Lf\n %.2Lf\n %.2Lf\n %.2Lf\n %.2Lf\n", z1, z2, z3, z4, z5, z6);

}