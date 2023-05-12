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
	// check if any vectors are size 0
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
		if (data[i].size() != tempSize) { // check if given data is a mxn dim matrix
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

const int LinearAlgebraLibrary::Matrix::getNumElem() {
	return rows * columns;
}

const double LinearAlgebraLibrary::Matrix::getValue(int rowNum, int colNum) {
	if (rowNum >= rows || colNum >= columns || rowNum < 0 || colNum < 0) {
		throw LinearAlgebraLibException("Position out of bounds of Matrix.");
	}
	else {
		return matrixData[rowNum][colNum];
	}
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
	if (m <= 0 || n <= 0) {
		throw LinearAlgebraLibException("Dimension cannot be negative or zero.");
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
	if (n <= 0) {
		throw LinearAlgebraLibException("Dimension cannot be negative or zero.");
	}
	else {
		if (n < rows) rows = n;
		if (n < columns) columns = n;
		if (n > rows) {
			for (int i = rows; i < n; i++) {
				matrixData.push_back(std::vector<double>());
				for (int j = 0; j < columns; j++) {
					matrixData[i].push_back(0.0);
				}
			}
			rows = n;
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

void LinearAlgebraLibrary::Matrix::setIdentity() {
	if (!this->isIdentity()) {
		int temp = (rows < columns) ? rows : columns;
		rows = temp;
		columns = temp;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrixData[i][j] = (i == j) ? 1.0 : 0.0;
			}
		}
	}
}

const bool LinearAlgebraLibrary::Matrix::isIdentity() {
	if (rows != columns) return false; // must be square
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				if (matrixData[i][j] != 1.0) {
					return false;
				}
			} else {
				if (matrixData[i][j] != 0.0) {
					return false;
				}
			}
		}
	}
	return true;
}

const int LinearAlgebraLibrary::Matrix::getNumRows() {
	return rows;
}

const int LinearAlgebraLibrary::Matrix::getNumColumns() {
	return columns;
}

const double LinearAlgebraLibrary::Matrix::getLargestValue() {
	double tempMax = matrixData[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			tempMax = (matrixData[i][j] > tempMax) ? matrixData[i][j] : tempMax;
		}
	}
	return tempMax;
}

const double LinearAlgebraLibrary::Matrix::getSmallestValue() {
	double tempMin = matrixData[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			tempMin = (matrixData[i][j] < tempMin) ? matrixData[i][j] : tempMin;
		}
	}
	return tempMin;
}

const int LinearAlgebraLibrary::Matrix::getRank() {
	return this->getCol().getNumColumns();
}


const int LinearAlgebraLibrary::Matrix::getNullity() {
	return this->getNul().getNumColumns();
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getCol() {
	LinearAlgebraLibrary::Matrix stub(1);
	return stub;
	// throw exception ?
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getNul() {
	LinearAlgebraLibrary::Matrix stub(1);
	return stub;
}

const bool LinearAlgebraLibrary::Matrix::isSquareMatrix() {
	return rows == columns;
}

const bool LinearAlgebraLibrary::Matrix::isVector() {
	return (rows == 1 || columns == 1); // test is rowvec,colvec, & not vec
}

const bool LinearAlgebraLibrary::Matrix::isLinearInd() {
	if (columns > rows) return false;
	return false; // stub
}

const bool LinearAlgebraLibrary::Matrix::isInvertible() {
	if (rows != columns) return false;
	std::vector<std::vector<double>> temp = matrixData;
	Matrix tempMat(temp);
	double tempDet = getDeterminant(tempMat);
	return (tempDet != 0.0);
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getTranspose() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::add(Matrix mat) {
	if (this->rows != mat.getNumRows() || this->columns != mat.getNumColumns()) {
		throw LinearAlgebraLibException("Matrices are not the same dimensions.");
	}
	else {
		std::vector<std::vector<double>> temp;
		for (int i = 0; i < this->rows; i++) {
			temp.push_back(std::vector<double>());
			for (int j = 0; j < this->columns; j++) {
				temp[i].push_back(this->matrixData[i][j] + mat.getValue(i, j));
			}
		}
		LinearAlgebraLibrary::Matrix retMat(temp);
		return retMat;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::sub(Matrix mat) {
	if (this->rows != mat.getNumRows() || this->columns != mat.getNumColumns()) {
		throw LinearAlgebraLibException("Matrices are not the same dimensions.");
	}
	else {
		std::vector<std::vector<double>> temp;
		for (int i = 0; i < rows; i++) {
			temp.push_back(std::vector<double>());
			for (int j = 0; j < columns; j++) {
				temp[i].push_back(this->matrixData[i][j] - mat.getValue(i, j));
			}
		}
		LinearAlgebraLibrary::Matrix retMat(temp);
		return retMat;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::mul(Matrix mat) {
	if (this->columns != mat.getNumRows()) {
		throw LinearAlgebraLibException("Matrices cannot be multiplied.");
	}
	else {
		LinearAlgebraLibrary::Matrix stub(1, 1);
		// dot product of rows
		return stub;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::copy() {
	std::vector<std::vector<double>> temp;
	for (int i = 0; i < rows; i++) {
		std::vector<double> rowVec;
		for (int j = 0; j < columns; j++) {
			rowVec.push_back(matrixData[i][j]);
		}
		temp.push_back(rowVec);
	}
	Matrix retMat(temp);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::power(int pow) {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {
		if (pow == 0) {
			// copy matrix and set identity and return
			Matrix retMat = this->copy();
			retMat.setIdentity();
			return retMat;
		}
		else if (pow == 1) {
			return this->copy();
		}
		else if (pow < 0) {
			// add negative test pow case later after get inverse.
			LinearAlgebraLibrary::Matrix stub(1, 1);
			return stub;
		}
		else {
			int i = pow;
			Matrix retMat = this->copy();
			while (i > 0) {
				retMat = retMat.mul(retMat);
				i++;
			}
			return retMat;
		}
		
	}
}

void LinearAlgebraLibrary::Matrix::apply(std::function<double(double)> fn) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrixData[i][j] = fn(matrixData[i][j]);
		}
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::ref() {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

void LinearAlgebraLibrary::Matrix::print() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matrixData[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::refY() {
	if (rows != 2 && columns != 1) {

	}
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
	Matrix stub(1, 1);
	return stub;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::customMatTransform(LinearAlgebraLibrary::Matrix transformMat) {
	Matrix stub(1, 1);
	return stub;
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
	if (row < 0 || row >= this->rows) {
		throw LinearAlgebraLibException("Row value not in matrix.");
	}
	else {
		std::vector<std::vector<double>> tempVec;
		tempVec.push_back(std::vector<double>());
		for (int i = 0; i < columns; i++) {
			tempVec[0].push_back(matrixData[row][i]);
		}
		Matrix retMat(tempVec);
		return retMat;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getColumn(int column) {
	LinearAlgebraLibrary::Matrix stub(1, 1);
	return stub;
}

const bool LinearAlgebraLibrary::Matrix::areEqual(LinearAlgebraLibrary::Matrix mat) {
	if (this->getNumRows() != mat.getNumRows() || this->getNumColumns() != mat.getNumColumns()) return false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixData[i][j] != mat.getValue(i, j)) return false;
		}
	}
	return true;
}












double LinearAlgebraLibrary::getDeterminant(Matrix mat) {
	if (mat.getNumRows() != mat.getNumColumns()) {
		throw LinearAlgebraLibException("Matrix must be square matrix.");
	}
	else {
		if (mat.allZeros()) return 0.0;
		if (mat.getNumRows() == 1) return mat.getValue(0, 0);
		if (mat.getNumRows() == 2) return ((mat.getValue(0, 0) * mat.getValue(1, 1)) - (mat.getValue(0, 1) * mat.getValue(1, 0)));
		// compute determinant using laplace expansion (cofactor expansion) for greater than 2x2 matrices
		double retval = 0.0;
		for (int j = 0; j < mat.getNumColumns(); j++) {
			retval += ((j % 2 == 0) ? 1.0 : -1.0) * mat.getValue(0, j) * getDeterminant(getSubMatrix(mat, 0, j));
		}
		return retval;
	}
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::getSubMatrix(Matrix& origMatrix, int rowToExclude, int columnToExclude) {
	std::vector<std::vector<double>> submatrixData;
	for (int i = 0; i < origMatrix.getNumRows(); i++) {
		if (i != rowToExclude) {
			std::vector<double> temp;
			for (int j = 0; j < origMatrix.getNumColumns(); j++) {
				if (j != columnToExclude) {
					temp.push_back(origMatrix.getValue(i, j));
				}
			}
			submatrixData.push_back(temp);
		}
	}
	Matrix subMatrix(submatrixData);
	return subMatrix;
}