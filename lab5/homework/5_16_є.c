#include <stdio.h>
#include <math.h>
double taylor_fraction(double x, double eps) {
    double sum = 0.0;
    double term = 1.0;


    while (fabs(term) >= eps) {
        sum += term;
        term = -term * x;
    }

    return sum;
}

int main() {
    double x, eps;

    printf("Enter value for x (|x| < 1)[cite: 16]: ");
    scanf("%lf", &x);


    if (fabs(x) >= 1.0) {
        printf("Error: according to the condition, |x| must be less than 1[cite: 16]!\n");
        return -1;
    }

    do {
        printf("Enter positive accuracy eps (> 0): ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    double my_result = taylor_fraction(x, eps);
    double math_result = 1.0 / (1.0 + x); 

    printf("\n--- Results for point (e)[cite: 16] ---\n");
    printf("Taylor series value:  %.10lf\n", my_result);
    printf("Exact value 1/(1+x):    %.10lf\n", math_result);
    printf("Difference:             %.10lf\n", fabs(my_result - math_result));

    return 0;
}