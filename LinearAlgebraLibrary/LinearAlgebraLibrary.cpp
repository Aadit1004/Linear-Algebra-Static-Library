// LinearAlgebraLibrary.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "LinearAlgebraLibrary.h"

LinearAlgebraLibrary::Matrix::Matrix(int m, int n) {
	if (n <= 0 || m <= 0) {
		throw LinearAlgebraLibException("Given dimension must be positive real number.");
	}
	else {
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
} 

LinearAlgebraLibrary::Matrix::Matrix(int n) {
	if (n <= 0) {
		throw LinearAlgebraLibException("Given dimension must be positive real number.");
	}
	else {
		rows = n;
		columns = n;
		// Set all values to Zero by defualt
		for (int i = 0; i < n; i++) {
			matrixData.push_back(std::vector<double>());
			for (int j = 0; j < n; j++) {
				matrixData[i].push_back(0.0);
			}
		}
	}
}

LinearAlgebraLibrary::Matrix::Matrix(std::vector<std::vector<double>> data) {
	if (data.size() == 0) {
		throw LinearAlgebraLibException("Given data must have size > 0");
	}
	else {
		for (std::vector<double> vec : data) {
			if (vec.size() == 0) {
				throw LinearAlgebraLibException("Given data must have size > 0");
			}
		}
	}
	int tempSize = (int) data[0].size();
	bool notBox = false;
	int i = 0;
	while (i < data.size()) {
		if (data[i].size() != tempSize) {
			notBox = true;
			break;
		}
		i++;
	}
	if (notBox) {
		throw LinearAlgebraLibException("Given matrix is not an mxn dimension matrix.");
	} else {
		rows = (int) data.size();
		columns = (int) data[0].size();
		matrixData = data;
	}
}

const double LinearAlgebraLibrary::Matrix::getValue(int rowNum, int colNum) { 
	if (rowNum >= rows || colNum >= columns || rowNum < 0 || colNum < 0) {
		throw LinearAlgebraLibException("Position out of bounds of Matrix.");
	}
	else {
		return matrixData[rowNum][colNum];
	}
}

const int LinearAlgebraLibrary::Matrix::getNumElem() {
	return rows * columns;
}

void LinearAlgebraLibrary::Matrix::setValue(double value, int rowNum, int colNum) {
	if (rowNum >= rows || colNum >= columns || rowNum < 0 || colNum < 0) {
		throw LinearAlgebraLibException("Position out of bounds of Matrix.");
	}
	else {
		matrixData[rowNum][colNum] = (double) value;
	}
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

const bool LinearAlgebraLibrary::Matrix::allZeros() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixData[i][j] != 0.0) {
				return false;
			}
		}
	}
	return true;
}

const bool LinearAlgebraLibrary::Matrix::allOnes() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixData[i][j] != 1.0) {
				return false;
			}
		}
	}
	return true;
}

void LinearAlgebraLibrary::Matrix::setRandom() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int temp = std::rand() % 101;
			matrixData[i][j] = (double) temp;
		}
	}
}

void LinearAlgebraLibrary::Matrix::setSize(int m, int n) {
	if (m < 0 || n < 0) {
		throw LinearAlgebraLibException("Dimension cannot be negative.");
	}
	else {
		if (m < rows) rows = m;
		if (n < columns) columns = n;
		if (m > rows) {
			for (int i = rows; i < m; i++) {
				matrixData.push_back(std::vector<double>());
				for (int j = 0; j < columns; j++) {
					matrixData[i].push_back(0.0);
				}
			}
			rows = m;
		}
		if (n > columns) {
			for (int i = 0; i < rows; i++) {
				for (int j = columns; j < n; j++) {
					matrixData[i].push_back(0.0);
				}
			}
			columns = n;
		}
	}
}

void LinearAlgebraLibrary::Matrix::setSize(int n) {
	// To do
}

void LinearAlgebraLibrary::Matrix::setIdentity() {
	int temp = (rows < columns) ? rows : columns;
	rows = temp;
	columns = temp;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrixData[i][j] = (i == j) ? 1.0 : 0.0;
		}
	}
}

const int LinearAlgebraLibrary::Matrix::getNumRows() {
	return rows;
}

const int LinearAlgebraLibrary::Matrix::getNumColumns() {
	return columns;
}

const double LinearAlgebraLibrary::Matrix::getDeterminant() {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	} else {
		// compute determinant
		return 0.0; //stub
	}
}

const double LinearAlgebraLibrary::Matrix::getLargestValue() {
	double tempMax = -1000000.0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			tempMax = (matrixData[i][j] < tempMax) ? matrixData[i][j] : tempMax;
		}
	}
	return tempMax;
}

const double LinearAlgebraLibrary::Matrix::getSmallestValue() {
	double tempMin = 1000000.0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			tempMin = (matrixData[i][j] < tempMin) ? matrixData[i][j] : tempMin;
		}
	}
	return tempMin;
}

const int LinearAlgebraLibrary::Matrix::getRank() {
	return 0; // stub
}


const int LinearAlgebraLibrary::Matrix::getNullity() {
	return 0; // stub
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getCol() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getNul() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

const bool LinearAlgebraLibrary::Matrix::isSquareMatrix() {
	return rows == columns;
}

const bool LinearAlgebraLibrary::Matrix::isDiagonalizable() {
	return false; // stub
}

const bool LinearAlgebraLibrary::Matrix::isLinearInd() {
	return false; // stub
}

const bool LinearAlgebraLibrary::Matrix::isVector() {
	return (rows == 1 || columns == 1);
}

const bool LinearAlgebraLibrary::Matrix::isInvertible() {
	return false; // stub
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getTranspose() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getInverse() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::add(Matrix mat) {
	if (this->rows != mat.rows || this->columns != mat.columns) {
		throw LinearAlgebraLibException("Matrices are not the same dimensions.");
	}
	else {
		std::vector<std::vector<double>> temp;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp[i][j] = this->matrixData[i][j] + mat.matrixData[i][j];
			}
		}
		//LinearAlgebraLibrary::Matrix retMat(temp);
		LinearAlgebraLibrary::Matrix retMat(1, 1);
		return retMat;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::sub(Matrix mat) {
	if (this->rows != mat.rows || this->columns != mat.columns) {
		throw LinearAlgebraLibException("Matrices are not the same dimensions.");
	}
	else {
		std::vector<std::vector<double>> temp;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp[i][j] = this->matrixData[i][j] - mat.matrixData[i][j];
			}
		}
		//LinearAlgebraLibrary::Matrix retMat(temp);
		LinearAlgebraLibrary::Matrix retMat(1, 1);
		return retMat;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::mul(Matrix mat) {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::ref() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::power(int exp) {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {
		LinearAlgebraLibrary::Matrix stub(1, 1);
		return stub;
	}
}

void LinearAlgebraLibrary::Matrix::print() {
	for (int i = 0; i < rows; i++) {
		std::cout << std::endl;
		for (int j = 0; j < columns; j++) {
			std::cout << matrixData[i][j] << " ";
		}
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::refY() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::refX() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::refYX() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::rot90() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::rot180() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::rot270() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

void LinearAlgebraLibrary::Matrix::apply(std::function<double(double)> fn) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrixData[i][j] = fn(matrixData[i][j]);
		}
	}
}

void LinearAlgebraLibrary::Matrix::setUpperTriangular() {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {

	}
}

void LinearAlgebraLibrary::Matrix::setLowerTriangular() {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {

	}
}

const bool LinearAlgebraLibrary::Matrix::isTriangularMatrix() {
	return false; // stub
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getRow(int row) {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getColumn(int column) {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}