#include "pch.h"
#include "Matrix.h"

Matrix::Matrix(int m, int n) {
	rows = m;
	columns = n;
}

void* Matrix::getValue(int rowNum, int colNum) {
	return matrixData[rowNum][colNum];
}