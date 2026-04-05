#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// initliaze the matrix A B and C
#define N 100  
#define M 100  
#define P 100  

int main() {
    int i, j, k;

    // Allocate matrices
    double A[N][M];
    double B[M][P];
    double C[N][P];

    // Initialize matrices A and B with random values
    srand(0);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            A[i][j] = rand() % 15;
        }
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            B[i][j] = rand() % 15;
        }
    }

    // Initialize result matrix C to 0
    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            C[i][j] = 0;
        }
    }

    // time log
    double start_p = omp_get_wtime();

    // Parallel matrix multiplication
    #pragma omp parallel for private(j, k)
    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            for (k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
     //timing
     double end_p = omp_get_wtime();
    double start_s = omp_get_wtime();

    for (i = 0; i < N; i++) {
        for (j = 0; j < P; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end_s = omp_get_wtime();
    //timing


    printf("Time taken for par: %f seconds\n", end_p - start_p);
    printf("Time taken for serial: %f seconds\n", end_s - start_s);

    return 0;
}