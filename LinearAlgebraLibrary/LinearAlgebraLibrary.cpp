// LinearAlgebraLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "LinearAlgebraLibrary.h"

LinearAlgebraLibrary::Matrix::Matrix(int m, int n) {
	rows = m;
	columns = n;
	// Set all values to Zero by defualt
}

LinearAlgebraLibrary::Matrix::Matrix(int n) {
	rows = n;
	columns = n;
	// Set all values to Zero by defualt
}

const double* LinearAlgebraLibrary::Matrix::getValue(int rowNum, int colNum) { 
	return matrixData[rowNum][colNum];
	// throw out of range exception
}

void LinearAlgebraLibrary::Matrix::setValue(double* value, int rowNum, int colNum) {
	matrixData[rowNum][colNum] = (double*)value;
}