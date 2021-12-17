#include "quantification.h"

int quant[m][n];

float Q[m][n] = {
	{16, 11, 10, 16,  24,  40,  51,  61},
	{12, 12, 14, 19,  26,  58,  60,  55},
	{14, 13, 16, 24,  40,  57,  69,  56},
	{14, 17, 22, 29,  51,  87,  80,  62},
	{18, 22, 37, 56,  68, 109, 103,  77},
	{24, 35, 55, 64,  81, 104, 133,  92},
	{49, 64, 78, 87, 103, 121, 129, 101},
	{72, 92, 95, 98, 112, 100, 103,  99}
};

void quantify(float matrix[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			quant[i][j] = round(matrix[i][j] / Q[i][j]);
		}
	}
	printMatrix(quant);
}

void printMatrix(int matrix[m][n]) {
	int i, j;
	printf("-------------- Printing %d x %d matrix ------------------- \n", m, n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}
