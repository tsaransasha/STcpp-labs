#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 100

int input_to_zero_int_array(int* arr, int max_size) {
    int i = 0;
    do {
        if (i >= max_size) {
            printf("Maximum array size reached (%d elements).\n", max_size);
            break;
        }

        printf("enter element %d (0 to stop): ", i + 1);
        int rscan_result = scanf("%d", &arr[i]);
        if (rscan_result != 1) {
            printf("invalid input\n");
            while (getchar() != '\n');
            return i;
        }
        if (arr[i] == 0) {
            return i;
        }
        i++;
    } while (1);
    return i;
}

void print_int_array(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool is_sqrt(int x) {
    if (x < 0) return false;
    int root = (int)(sqrt(x) + 0.5);
    return root * root == x;
}

bool is_cube(int x) {

    int root = (int)(cbrt(x) + (x < 0 ? -0.5 : 0.5));
    return root * root * root == x;
}

void print_sqrt_and_cube(const int* arr, int n) {
    int k1 = 0, k2 = 0;
    for (int i = 0; i < n; i++) {
        if (is_sqrt(arr[i])) {
            printf("%d is a perfect square\n", arr[i]);
            k1++;
        }
        if (is_cube(arr[i])) {
            printf("%d is a perfect cube\n", arr[i]);
            k2++;
        }
    }
    printf("\nquantity of perfect squares is %d\n", k1);
    printf("quantity of cubes is %d\n", k2);
}

int main() {
    int* arr = (int*)malloc(MAX_ARRAY_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("not enough memory\n");
        return EXIT_FAILURE;
    }
    
    int n = input_to_zero_int_array(arr, MAX_ARRAY_SIZE);

    printf("\nyour array: \n");
    print_int_array(arr, n);
    
    printf("\nperfect squares and cubes in array:\n");
    print_sqrt_and_cube(arr, n);

    free(arr);
    return EXIT_SUCCESS;
}