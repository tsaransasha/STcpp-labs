//
// Created by Олександра
//
#include <stdio.h>
#include <math.h>

void solve_quadratic(double a, double b, double c) {
    printf("Quadratic: %g*x^2 + %g*x + %g = 0", a, b, c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Infinite number of solutions (any x).\n");
            } else {
                printf("No solutions (0 = %g is impossible).\n", c);
            }
        } else {
            double x = -c / b;
            printf("Linear equation. 1 solution: x = %g\n", x);
        }
        return;
    }

    double d = b * b - 4 * a * c;
    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        printf("2 solutions:\n  x1 = %g\n  x2 = %g\n", x1, x2);
    } else if (d == 0) {
        double x = -b / (2 * a);
        printf("1 solution:\n  x = %g\n", x);
    } else {
        printf("No real solutions (D < 0).\n");
    }
}

void solve_biquadratic(double a, double b, double c) {
    printf("Biquadratic: %g*x^4 + %g*x^2 + %g = 0", a, b, c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Infinite number of solutions (any x).\n");
            } else {
                printf("No solutions.\n");
            }
        } else {
            double y = -c / b;
            if (y > 0) {
                printf("2 solutions:\n  x1 = %g\n  x2 = %g\n", sqrt(y), -sqrt(y));
            } else if (y == 0) {
                printf("1 solution:\n  x = 0\n");
            } else {
                printf("No real solutions (x^2 < 0).\n");
            }
        }
        return;
    }

    double d = b * b - 4 * a * c;
    if (d < 0) {
        printf("No real solutions (D < 0).\n");
        return;
    }

    double y1 = (-b + sqrt(d)) / (2 * a);
    double y2 = (-b - sqrt(d)) / (2 * a);

    if (d == 0) {
        if (y1 > 0) {
            printf("2 solutions:\n  x1 = %g\n  x2 = %g\n", sqrt(y1), -sqrt(y1));
        } else if (y1 == 0) {
            printf("1 solution:\n  x = 0\n");
        } else {
            printf("No real solutions.\n");
        }
    } else {
        if (y1 > 0 && y2 > 0) {
            printf("4 solutions:\n  x1 = %g\n  x2 = %g\n  x3 = %g\n  x4 = %g\n",
                   sqrt(y1), -sqrt(y1), sqrt(y2), -sqrt(y2));
        } else if ((y1 > 0 && y2 == 0) || (y2 > 0 && y1 == 0)) {
            double pos_y = (y1 > 0) ? y1 : y2;
            printf("3 solutions:\n  x1 = %g\n  x2 = %g\n  x3 = 0\n", sqrt(pos_y), -sqrt(pos_y));
        } else if ((y1 > 0 && y2 < 0) || (y2 > 0 && y1 < 0)) {
            double pos_y = (y1 > 0) ? y1 : y2;
            printf("2 solutions:\n  x1 = %g\n  x2 = %g\n", sqrt(pos_y), -sqrt(pos_y));
        } else if ((y1 == 0 && y2 < 0) || (y2 == 0 && y1 < 0)) {
            printf("1 solution:\n  x = 0\n");
        } else {
            printf("No real solutions (both y < 0).\n");
        }
    }
}

int main() {
    double a, b, c;
    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    solve_quadratic(a, b, c);
    solve_biquadratic(a, b, c);

    return 0;
}