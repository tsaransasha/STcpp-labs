

#ifndef LABSST_MATRIX_H
#define LABSST_MATRIX_H
typedef double** MATRIX;

MATRIX input_matrix(int n);
MATRIX add_matrix(MATRIX mat1, MATRIX mat2, int rows, int cols);
MATRIX multiply_matrix(MATRIX mat1, MATRIX mat2, int n);
void print_matrix(MATRIX mat, int n);
void delete_matrix(MATRIX mat, int n);
#endif //LABSST_MATRIX_H
