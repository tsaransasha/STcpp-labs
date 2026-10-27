#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double** create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return NULL;
    double** mat = (double**)malloc(rows * sizeof(double*));
    if (!mat) return NULL;
    
    for (int i = 0; i < rows; i++) {
        mat[i] = (double*)malloc(cols * sizeof(double));
        if (!mat[i]) {
            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}


void fill_matrix_random(double** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = (rand() % 200 - 100) / 10.0; // Випадкові дійсні числа від -10.0 до 10.0
        }
    }
}


void print_matrix(double** mat, int rows, int cols) {
    if (!mat) return;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}


void delete_matrix(double** mat, int rows) {
    if (!mat) return;
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);
}


double** insert_row_after_even(double** mat, int* rows, int cols) {
    if (!mat || *rows <= 0 || cols <= 0) return mat;


    int even_count = 0;
    for (int i = 0; i < *rows; i++) {
        if (i % 2 == 0) {
            even_count++;
        }
    }

    int new_rows = *rows + even_count;
    

    double** new_mat = (double**)malloc(new_rows * sizeof(double*));
    if (!new_mat) return mat;

    int r = 0;
    for (int i = 0; i < *rows; i++) {

        new_mat[r] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            new_mat[r][j] = mat[i][j];
        }
        r++;


        if (i % 2 == 0) {
            new_mat[r] = (double*)calloc(cols, sizeof(double));

            r++;
        }
    }


    delete_matrix(mat, *rows);
    *rows = new_rows;

    return new_mat;
}

int main() {
    srand(time(NULL));
    int n, m;

    printf("Enter number of rows (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid rows!\n");
        return EXIT_FAILURE;
    }

    printf("Enter number of columns (M): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid columns!\n");
        return EXIT_FAILURE;
    }

    double** matrix = create_matrix(n, m);
    if (!matrix) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    fill_matrix_random(matrix, n, m);

    printf("\n--- Original Matrix (%d x %d) ---\n", n, m);
    print_matrix(matrix, n, m);

    matrix = insert_row_after_even(matrix, &n, m);

    printf("\n--- Modified Matrix (After even rows) ---\n");
    print_matrix(matrix, n, m);

    delete_matrix(matrix, n);

    return EXIT_SUCCESS;
}