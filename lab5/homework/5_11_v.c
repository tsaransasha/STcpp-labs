#include <stdio.h>
#include <math.h>

double calculate_sum_v(int n) {
    if (n <= 0) return 0.0;

    double S = 0.0;
    double a_prev2 = 1.0;
    double a_prev1 = 1.0;
    double fact = 1.0;

    for (int k = 1; k <= n; k++) {
        double current_a;

        if (k == 1) {
            current_a = 1.0;
        } else if (k == 2) {
            current_a = 1.0;
        } else {

            current_a = a_prev1 + a_prev2 / pow(2.0, k);
            a_prev2 = a_prev1;
            a_prev1 = current_a;
        }


        fact *= k;


        S += fact / current_a;
    }

    return S;
}

int main() {
    int n;
    printf("Enter a value for n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wrong input.\n");
        return -1;
    }

    double result = calculate_sum_v(n);
    printf("S_%d = %.10lf\n", n, result);

    return 0;
}