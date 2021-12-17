// dct.cpp
//

#include "dct.h"

// Function to find discrete cosine transform and print it
void dctTransform(int matrix[m][n], float matrixf[m][n])
{
    int i, j, k, l;

    // dct will store the discrete cosine transform
    float dct[m][n];


    float ci, cj, dct1, sum;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {

            // ci and cj depends on frequency as well as
            // number of row and columns of specified matrix
            if (i == 0)
                ci = 1 / sqrt(m);
            else
                ci = sqrt(2) / sqrt(m);
            if (j == 0)
                cj = 1 / sqrt(n);
            else
                cj = sqrt(2) / sqrt(n);

            // sum will temporarily store the sum of
            // cosine signals
            sum = 0;
            for (k = 0; k < m; k++) {
                for (l = 0; l < n; l++) {
                    dct1 = matrix[k][l] *
                        cos((2 * k + 1) * i * pi / (2 * m)) *
                        cos((2 * l + 1) * j * pi / (2 * n));
                    sum = sum + dct1;
                }
            }
            matrixf[i][j] = ci * cj * sum;
        }
    }

    //matrixf = dct;
    printMatrix(matrixf);
}


void printMatrix(float matrix[m][n]) {
    int i, j;
    printf("-------------- Printing %d x %d matrix ------------------- \n", m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n-------------------------------------\n");
}




