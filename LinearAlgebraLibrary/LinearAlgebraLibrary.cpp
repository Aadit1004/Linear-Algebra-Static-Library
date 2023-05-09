// LinearAlgebraLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "LinearAlgebraLibrary.h"

LinearAlgebraLibrary::Matrix::Matrix(int m, int n) {
	rows = m;
	columns = n;
	// Set all values to Zero by defualt
	for (int i = 0; i < m; i++) {
		matrixData.push_back(std::vector<double>());
		for (int j = 0; j < n; j++) {
			matrixData[i].push_back(0.0);
		}
	}
}

LinearAlgebraLibrary::Matrix::Matrix(int n) {
	rows = n;
	columns = n;
	// Set all values to Zero by defualt
	for (int i = 0; i < n; i++) {
		matrixData.push_back(std::vector<double>());
		for (int j = 0; j < n; j++) {
			matrixData[i].push_back(1.0);
		}
	}
}

LinearAlgebraLibrary::Matrix::Matrix(std::vector<std::vector<double>> data) {
	rows = (int) data.size();
	columns = (int) data[1].size();
	matrixData = data;
	// add a check if it is a box matrix or not
}

const double LinearAlgebraLibrary::Matrix::getValue(int rowNum, int colNum) { 
	return matrixData[rowNum][colNum];
	// throw out of range exception
}

const int LinearAlgebraLibrary::Matrix::getNumElem() {
	return rows * columns;
}

void LinearAlgebraLibrary::Matrix::setValue(double value, int rowNum, int colNum) {
	matrixData[rowNum][colNum] = (double) value;
	// throw out of range exception
}


void LinearAlgebraLibrary::Matrix::setOnes() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrixData[i][j] = 1.0;
		}
	}
}


void LinearAlgebraLibrary::Matrix::setZeros() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrixData[i][j] = 0.0;
		}
	}
}

void LinearAlgebraLibrary::Matrix::setRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int temp = std::rand() % 101;
			matrixData[i][j] = (double) temp;
		}
	}
}