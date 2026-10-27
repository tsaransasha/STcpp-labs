#include <stdio.h>
#include <stdlib.h>

int input_array(unsigned n, double *arr) {
    for (unsigned int i = 0; i < n; i++) {
        printf("enter element %u: ", i + 1);

        if (scanf("%lf", &arr[i]) != 1) {
            printf("wrong input\n");
            return i;
        }
    }
    return n;
}

void print_array(unsigned n, const double *arr) {
    for (unsigned int i = 0; i < n; i++) {
        printf("%g, ", arr[i]);
    }
    printf("\n");
}

double sum_squares(const double *arr, unsigned n) {
    double sum = 0.0;
    for (unsigned int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }
    return sum;
}

int main() {
    unsigned int n;
    printf("enter n: ");
    if (scanf("%u", &n) != 1 || n == 0) {
        printf("invalid n\n");
        return EXIT_FAILURE;
    }

    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("memory allocation failed\n");
        return EXIT_FAILURE;
    }

    if (input_array(n, arr) != n) {
        free(arr);
        return EXIT_FAILURE;
    }

    print_array(n, arr);
    printf("\n");

    printf("sum of squares: %lf\n", sum_squares(arr, n));

    free(arr);
    return EXIT_SUCCESS;
}

