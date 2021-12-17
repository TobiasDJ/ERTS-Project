#ifndef __DCT_H__
#define __DCT_H__


#include <iostream>
#include <cmath> 
using namespace std;

#define pi 3.142857
const int m = 8, n = 8;

void dctTransform(int matrix[m][n], float matrixf[m][n]);
void printMatrix(float matrix[m][n]);

#endif


