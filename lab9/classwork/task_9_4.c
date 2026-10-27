#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
    int n;
    printf("enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }

    MATRIX mat1 = input_matrix(n);
    if (mat1 == NULL) return 1;

    MATRIX mat2 = input_matrix(n);
    if (mat2 == NULL) {
        delete_matrix(mat1, n);
        return 1;
    }

    MATRIX sum = add_matrix(mat1, mat2, n, n);
    MATRIX product = multiply_matrix(mat1, mat2, n);

    if (sum != NULL) {
        printf("sum = \n");
        print_matrix(sum, n);
    }
    
    if (product != NULL) {
        printf("product = \n");
        print_matrix(product, n);
    }

    delete_matrix(mat1, n);
    delete_matrix(mat2, n);
    if (sum) delete_matrix(sum, n);
    if (product) delete_matrix(product, n);

    return 0;
}