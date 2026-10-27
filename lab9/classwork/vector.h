#ifndef LABSST_VECTOR_H
#define LABSST_VECTOR_H

double* input_vector(int n);
double* add_vectors(const double* v1, const double* v2, int n);
double* subtract_vectors(const double* v1, const double* v2, int n);
void print_vector(const double* v, int n);
void delete_vector(double* v);

#endif
