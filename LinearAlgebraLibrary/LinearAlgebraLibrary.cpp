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
	return this->getColSpace().getNumColumns();
}


const int LinearAlgebraLibrary::Matrix::getNullity() {
	return this->getNulSpace().getNumColumns(); // check if { {0.0} };
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getColSpace() {
	LinearAlgebraLibrary::Matrix stub(1);
	return stub;
	// throw exception ?
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::getNulSpace() {
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

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::add(Matrix& mat) {
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

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::sub(Matrix& mat) {
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

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::Matrix::mul(Matrix& mat) {
	if (this->columns != mat.getNumRows()) {
		throw LinearAlgebraLibException("Matrices cannot be multiplied.");
	}
	else {
		std::vector<std::vector<double>> retVec;
		for (int i = 0; i < this->rows; i++) {
			std::vector<double> temp;
			for (int j = 0; j < mat.getNumColumns(); j++) {
				double dotProduct = 0;
				for (int k = 0; k < this->columns; k++) {
					dotProduct += this->matrixData[i][k] * mat.getValue(k, j);
				}
				temp.push_back(dotProduct);
			}
			retVec.push_back(temp);
		}
		LinearAlgebraLibrary::Matrix retMat(retVec);
		return retMat;
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
			// add negative test pow case later after get inverse fn.
			// get inv and take it to the abs(pow)
			LinearAlgebraLibrary::Matrix stub(1, 1);
			return stub;
		}
		else {
			// use exponentiation by squaring for powers greater than 1
			if (pow % 2 == 0) { // if even power
				Matrix halfPower = this->power(pow / 2);
				return halfPower.mul(halfPower);
			}
			else { // if odd power
				Matrix halfPower = this->power((pow - 1) / 2); // compute for (pow - 1 / 2)
				halfPower = halfPower.mul(halfPower);
				return this->mul(halfPower);
			}
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

void LinearAlgebraLibrary::Matrix::setUpperTriangular() {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {
		if (rows == 1) return;
		for (int i = 1; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (i > j) {
					matrixData[i][j] = 0.0;
				}
			}
		}
	}
}

void LinearAlgebraLibrary::Matrix::setLowerTriangular() {
	if (rows != columns) {
		throw LinearAlgebraLibException("Matrix must be square matrix");
	}
	else {
		if (rows == 1) return;
		for (int i = 0; i < rows; i++) {
			for (int j = 1; j < columns; j++) {
				if (j > i) {
					matrixData[i][j] = 0.0;
				}
			}
		}
	}
}

const bool LinearAlgebraLibrary::Matrix::isTriangularMatrix() {
	if (rows != columns) return false;
	return (isUpper() || isLower());
}

bool LinearAlgebraLibrary::Matrix::isUpper() {
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i > j) {
				if (matrixData[i][j] != 0.0) return false;
			}
		}
	}
	return true;
}

bool LinearAlgebraLibrary::Matrix::isLower() {
	for (int i = 1; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (j > i) {
				if (matrixData[i][j] != 0.0) return false;
			}
		}
	}
	return true;
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
	if (column < 0 || column >= this->columns) {
		throw LinearAlgebraLibException("Column value not in matrix.");
	}
	else {
		std::vector<std::vector<double>> tempVec;
		for (int i = 0; i < rows; i++) {
			tempVec.push_back(std::vector<double>());
			tempVec[i].push_back(matrixData[i][column]);
		}
		Matrix retMat(tempVec);
		return retMat;
	}
}

const bool LinearAlgebraLibrary::Matrix::areEqual(LinearAlgebraLibrary::Matrix& mat) {
	if (this->getNumRows() != mat.getNumRows() || this->getNumColumns() != mat.getNumColumns()) return false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrixData[i][j] != mat.getValue(i, j)) return false;
		}
	}
	return true;
}

LinearAlgebraLibrary::Vec::Vec(int size) {
	if (size < 0) {
		throw LinearAlgebraLibException("Size cannot be negative.");
	}
	else {
		if (size == 0) {
			vecSize = 0;
			lastPos = -1;
			std::vector<double> temp{};
			vecData = temp;
		}
		else {
			vecSize = size;
			lastPos = size - 1;
			int temp = size;
			while (temp > 0) {
				vecData.push_back(0.0);
			}
		}
	}
}

LinearAlgebraLibrary::Vec::Vec(std::vector<double> data) {
	vecData = data;
	vecSize = data.size();
	lastPos = vecSize - 1;
}













LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::refY(Matrix& mat) {
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> reflectOverY{ {-1.0, 0.0}, {0.0, 1.0} };
	LinearAlgebraLibrary::Matrix reflectYTransformMat(reflectOverY);
	LinearAlgebraLibrary::Matrix retMat = reflectYTransformMat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::refX(Matrix& mat) { 
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> reflectOverX{ {1.0, 0.0}, {0.0, -1.0} };
	LinearAlgebraLibrary::Matrix reflectXTransformMat(reflectOverX);
	LinearAlgebraLibrary::Matrix retMat = reflectXTransformMat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::refYX(Matrix& mat) {
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> reflectOverYX{ {0.0, 1.0}, {1.0, 0.0} };
	LinearAlgebraLibrary::Matrix ReflectYXTransformMat(reflectOverYX);
	LinearAlgebraLibrary::Matrix retMat = ReflectYXTransformMat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::rot90(Matrix& mat) {
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> rotate90{ {0.0, -1.0}, {1.0, 0.0} };
	LinearAlgebraLibrary::Matrix rotate90Mat(rotate90);
	LinearAlgebraLibrary::Matrix retMat = rotate90Mat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::rot180(Matrix& mat) {
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> rotate180{ {-1.0, 0.0}, {0.0, -1.0} };
	LinearAlgebraLibrary::Matrix rotate180Mat(rotate180);
	LinearAlgebraLibrary::Matrix retMat = rotate180Mat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::rot270(Matrix& mat) {
	if (mat.getNumRows() != 2 || mat.getNumColumns() != 1) {
		throw LinearAlgebraLibrary::LinearAlgebraLibException("Matrix must be 2 x 1 dimension.");
	}
	std::vector<std::vector<double>> rotate270{ {0.0, 1.0}, {-1.0, 0.0} };
	LinearAlgebraLibrary::Matrix rotate270Mat(rotate270);
	LinearAlgebraLibrary::Matrix retMat = rotate270Mat.mul(mat);
	return retMat;
}

LinearAlgebraLibrary::Matrix LinearAlgebraLibrary::customMatTransform(Matrix& origMat, Matrix& transformMat) {
	Matrix stub(1, 1);
	return stub;
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