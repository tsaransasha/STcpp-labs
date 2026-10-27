#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


MATRIX input_matrix(int n) {
    if (n <= 0) return NULL;
    

    double** mat = (double**)malloc(n * sizeof(double*));
    if (mat == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {

        mat[i] = (double*)calloc(n, sizeof(double));
        if (mat[i] == NULL) {
            printf("Memory allocation failed!\n");

            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}


MATRIX add_matrix(MATRIX mat1, MATRIX mat2, int rows, int cols) {
    if (!mat1 || !mat2 || rows <= 0 || cols <= 0) return NULL;
    
    MATRIX result = (double**)malloc(rows * sizeof(double*));
    if (!result) return NULL;
    
    for (int i = 0; i < rows; i++) {
        result[i] = (double*)malloc(cols * sizeof(double));
        if (!result[i]) {
            for (int j = 0; j < i; j++) free(result[j]);
            free(result);
            return NULL;
        }
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}


MATRIX multiply_matrix(MATRIX mat1, MATRIX mat2, int n) {
    if (!mat1 || !mat2 || n <= 0) return NULL;
    
    MATRIX result = (double**)malloc(n * sizeof(double*));
    if (!result) return NULL;
    
    for (int i = 0; i < n; i++) {
        result[i] = (double*)calloc(n, sizeof(double)); // Ініціалізація нулями
        if (!result[i]) {
            for (int j = 0; j < i; j++) free(result[j]);
            free(result);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}


void print_matrix(MATRIX mat, int n) {
    if (!mat) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}


void delete_matrix(MATRIX mat, int n) {
    if (!mat) return;
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}