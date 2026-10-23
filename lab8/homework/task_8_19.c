#include <stdio.h>
#include <stdlib.h>

#define M_MAX 100
#define N_MAX 100

void inputArray(int array[M_MAX][N_MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[i][j]);
        }
    }
}

void printArray(int array[M_MAX][N_MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int findElement(int array[M_MAX][N_MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int max = 1;
            int min = 1;

            for (int k = 0; k < n; k++) {
                if (array[i][k] > array[i][j]) {
                    max = 0;
                }
            }

            for (int k = 0; k < m; k++) {
                if (array[k][j] < array[i][j]) {
                    min = 0;
                }
            }

            if (max == 1 && min == 1) {
                return array[i][j];
            }
        }
    }

    return 0;
}

int main() {
    int m, n;
    int array[M_MAX][N_MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter array elements:\n");
    inputArray(array, m, n);

    printf("The elements of the array are:\n");
    printArray(array, m, n);

    int result = findElement(array, m, n);

    printf("The required element is: %d\n", result);

    return 0;
}