#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_power_of_two(unsigned long long x) {
    if (x == 0) return false;
    return (x & (x - 1)) == 0;
}

bool is_power_of_three(unsigned long long x) {
    if (x == 0) return false;
    while (x % 3 == 0) {
        x /= 3;
    }
    return x == 1;
}

int main() {
    unsigned int n;
    printf("Enter natural number n: ");
    if (scanf("%u", &n) != 1 || n == 0) {
        printf("Invalid input for n.\n");
        return EXIT_FAILURE;
    }


    unsigned long long* arr = (unsigned long long*)malloc(n * sizeof(unsigned long long));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }


    for (unsigned int i = 0; i < n; i++) {
        printf("Enter element %u: ", i + 1);
        if (scanf("%llu", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return EXIT_FAILURE;
        }
    }

    int count_pow2 = 0;
    int count_pow3 = 0;


    for (unsigned int i = 0; i < n; i++) {
        if (is_power_of_two(arr[i])) {
            count_pow2++;
        }
        if (is_power_of_three(arr[i])) {
            count_pow3++;
        }
    }


    printf("\nYour array: ");
    for (unsigned int i = 0; i < n; i++) {
        printf("%llu ", arr[i]);
    }
    printf("\n");

    printf("Quantity of powers of 2: %d\n", count_pow2);
    printf("Quantity of powers of 3: %d\n", count_pow3);


    free(arr);
    return EXIT_SUCCESS;
}