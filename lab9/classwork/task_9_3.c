#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
    int n;
    printf("Enter size of the vectors: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size!\n");
        return EXIT_FAILURE;
    }

    double* v1 = input_vector(n);
    double* v2 = input_vector(n);
    
    if (v1 == NULL || v2 == NULL) {
        delete_vector(v1);
        delete_vector(v2);
        return EXIT_FAILURE;
    }

    double* v_sum = add_vectors(v1, v2, n);
    double* v_sub = subtract_vectors(v1, v2, n);

    if (v_sum != NULL) {
        printf("The sum of the vectors is: ");
        print_vector(v_sum, n);
    }
    
    if (v_sub != NULL) {
        printf("The subtraction of the vectors is: ");
        print_vector(v_sub, n);
    }


    delete_vector(v_sum);
    delete_vector(v_sub);
    delete_vector(v1);
    delete_vector(v2);

    return EXIT_SUCCESS;
}