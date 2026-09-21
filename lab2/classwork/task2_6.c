//
// Created by Олександра

#include <stdio.h>
#include <math.h>

double calculate_distance(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}
double calculate_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double xa, ya, xb, yb, xc, yc;

    printf("Enter cordinates:\n");
    if (scanf("%lf %lf", &xa, &ya) != 2) return 1;
    if (scanf("%lf %lf", &xb, &yb) != 2) return 1;
    if (scanf("%lf %lf", &xc, &yc) != 2) return 1;
    double ab = calculate_distance(xa, ya, xb, yb);
    double bc = calculate_distance(xb, yb, xc, yc);
    double ca = calculate_distance(xc, yc, xa, ya);
    double area = calculate_area(ab, bc, ca);
    printf("Площа трикутника дорівнює: %.4lf\n", area);
    return 0;
}
