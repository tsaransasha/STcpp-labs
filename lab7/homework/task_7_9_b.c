#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements must be greater than 0.\n");
        return 1;
    }

    double a[n];
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    double min_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }

    printf("Minimum value: %lf\n", min_val);

    return 0;
}