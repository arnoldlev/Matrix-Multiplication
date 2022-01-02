/*
Arnold Lev
Matrix Multiplication Project
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct matrix multiply (struct matrix m1, struct matrix m2);
struct matrix {
    float **mat;
    int row;
    int columns;
};

int main() {
    char input[4];
    printf("Enter the size for Matrix #1: mxn\n");
    scanf("%s", input);
    struct matrix m1;
    m1.row = atoi(&input[0]);
    m1.columns = atoi(&input[2]);
    m1.mat = (float**) malloc(m1.row * sizeof(float*));
    for (int i = 0; i < m1.row; i++) {
        *(m1.mat + i) = (float*) malloc(m1.columns * sizeof(float));
    }
    printf("Enter the size for Matrix #2: mxn\n");
    scanf("%s", input);
    struct matrix m2;
    m2.row = atoi(&input[0]);
    m2.columns = atoi(&input[2]);
    m2.mat = (float**) malloc (m2.row * sizeof(float*));
    for (int i = 0; i < m2.row; i++) {
         *(m2.mat + i) = (float*) malloc(m2.columns * sizeof(float));
    }
    printf("Enter the values for Matrix #1\n");
    for (int i = 0; i < m1.row; i++) {
        for (int j = 0; j < m1.columns; j++) {
            scanf("%f", &m1.mat[i][j]);
       }
    }
    printf("\nEnter the values for Matrix #2\n");
    for (int i = 0; i < m2.row; i++) {
       for (int j = 0; j < m2.columns; j++) {
            scanf("%f", &m2.mat[i][j]);
        }
    }
    printf("\nMatrix #1:\n");
    for (int i = 0; i < m1.row; i++) {
        for (int j = 0; j < m1.columns; j++) {
            printf("%.1f ", m1.mat[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix #2:\n");
    for (int i = 0; i < m2.row; i++) {
        for (int j = 0; j < m2.columns; j++) {
            printf("%.1f ", m2.mat[i][j]);
        }
        printf ("\n");
    }
    struct matrix result = multiply (m1, m2);
    printf ("\nMultiplied Matrix:\n");
    for (int i = 0; i < result.row; i++) {
        for (int j = 0; j < result.columns; j++) {
            printf("%.1f ", result.mat[i][j]);
        }
        printf("\n");
    }
    /* Deallocate all the memory */
    for (int i = 0; i < m1.row; i++) {
        free(m1.mat[i]);
    }
    for (int i = 0; i < m2.row; i++) {
        free(m2.mat[i]);
    }
    for (int i = 0; i < result.row; i++) {
        free(result.mat[i]);
    }
    free(result.mat);
    free(m1.mat);
    free(m2.mat);
    return 0;
}

/*
    Time Complexity: O(n^2*m)
*/
struct matrix multiply (struct matrix m1, struct matrix m2) {
    if (m1.columns != m2.row) {
        printf("Error: Matrix sizes are invalid for multiplying\n");
        exit(-1);
    }
    struct matrix m3;
    m3.row = m1.row;
    m3.columns = m2.columns;
    m3.mat = (float**) malloc(m3.row * sizeof(float*));
    for (int i = 0; i < m3.row; i++) {
        *(m3.mat + i) = (float*) malloc(m3.columns * sizeof(float));
    }
    for (int r = 0; r < m3.row; r++) {
        for (int c = 0; c < m3.columns; c++) {
            for (int i = 0; i < m1.columns; i++) {
                m3.mat[r][c] += m1.mat[r][i] * m2.mat[i][c];
            }
       }
    }
    return m3;
}
