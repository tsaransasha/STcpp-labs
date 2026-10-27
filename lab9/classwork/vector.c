#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


double* input_vector(int n) {
    if (n <= 0) return NULL;
    double* v = (double*)malloc(n * sizeof(double));
    if (v == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%lf", &v[i]);
    }
    return v;
}


double* add_vectors(const double* v1, const double* v2, int n) {
    if (!v1 || !v2 || n <= 0) return NULL;
    double* result = (double*)malloc(n * sizeof(double));
    if (result == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] + v2[i];
    }
    return result;
}


double* subtract_vectors(const double* v1, const double* v2, int n) {
    if (!v1 || !v2 || n <= 0) return NULL;
    double* result = (double*)malloc(n * sizeof(double));
    if (result == NULL) return NULL;
    
    for (int i = 0; i < n; i++) {
        result[i] = v1[i] - v2[i];
    }
    return result;
}


void print_vector(const double* v, int n) {
    if (!v) return;
    for (int i = 0; i < n; i++) {
        printf("%g ", v[i]);
    }
    printf("\n");
}


void delete_vector(double* v) {
    free(v);
}