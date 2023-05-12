// LinearAlgebraLibrary.h
#pragma once
#include <functional>
#include <vector>
#include <stdlib.h>
#include <exception>
#include <string>
#include <iostream>
#include <math.h>

namespace LinearAlgebraLibrary {

	class LinearAlgebraLibException : public std::exception {
	private:
		std::string message;
	public:
		LinearAlgebraLibException(std::string msg) : message(msg) {}
		std::string what() { return message;}
	};

	class Matrix {

	private:

		int rows;
		int columns;
		std::vector<std::vector<double>> matrixData;

		Matrix copy();

	public:

		// Constructor (must be > 0)
		Matrix(int m, int n);

		// Constructor for Square Matrix (must be > 0)
		Matrix(int n);

		// Constructor with given values (must be > 0)
		Matrix(std::vector<std::vector<double>> data);

		// get number of elements in matrix
		const int getNumElem();

		// Get value from pos (0 indexed)
		const double getValue(int rowNum, int colNum);

		// Set value at pos
		void setValue(double value, int rowNum, int colNum);

		// Set full matrix filled with 1s
		void setOnes();

		// Set full matrix filled with 0s
		void setZeros();

		// Set full matrix filled with random double from 0.0 to 100.0
		void setRandom();

		// Resize matrix to new dimensions, if larger->new values are 0s
		void setSize(int m, int n);

		// Resize matrix to square size
		void setSize(int n);

		// Sets matrix to identity matrix to size of lower dim
		void setIdentity();

		// Get number of rows
		const int getNumRows();

		// Get number of columns
		const int getNumColumns();

		// returns true if every element is zero
		const bool allZeros();

		// returns true if every element is one
		const bool allOnes();

		// Returns largest value in matrix
		const double getLargestValue();

		// returns smallest value in matrix
		const double getSmallestValue();

		// returns the rank of the matrix (dimension of Col space)
		const int getRank();

		// returns the nullity of the matrix (dimension of the Null space)
		const int getNullity();

		// Returns the Column Space of the matrix
		Matrix getCol();

		// Returns the Null Space of the matrix
		Matrix getNul();

		// Is matrix a square nxn matrix
		const bool isSquareMatrix();

		// Is matrix an identity matrix
		const bool isIdentity();

		// Returns true if matrix rows are linearly independent, false otherwise
		const bool isLinearInd();

		// returns true if matrix is a row or column vector, false otherwise
		const bool isVector();

		// returns true if square matrix and columns are lin ind
		const bool isInvertible();

		// Get transpose of matrix
		Matrix getTranspose();

		// Return the addition from this matrix and mat if possible
		Matrix add(Matrix& mat);

		// Return the subtraction from this matrix and mat if possible
		Matrix sub(Matrix& mat);

		// Return the multiplication from this matrix and mat if possible
		Matrix mul(Matrix& mat);

		// Compute and return the Row Echelon Form of the matrix
		Matrix ref();

		// Takes this matrix and raises it to a power (must be square?)
		Matrix power(int pow);

		// Print the Matrix (cout)
		void print(); //needed?

		// apply a function to each element in matrix to modify it, fn must take in double and return double
		void apply(std::function<double(double)> fn);

		// set upper right triangle to values and bottom left values to 0, must be square // triangular matrix
		void setUpperTriangular();

		// set lower left triangle to values and uper right values to 0, must be square // triangular matrix
		void setLowerTriangular();

		// returns true if matrix is a upper right or lower left special triangle // triangular matrix
		const bool isTriangularMatrix();

		// return the given row (0 indexed) as a matrix
		Matrix getRow(int row);

		// return the given column (0 indexed) as a matrix
		Matrix getColumn(int column);

		// returs true if this and mat are same dim and all elems are the same
		const bool areEqual(LinearAlgebraLibrary::Matrix& mat);

	};

	class Vec {

	private:

		int size;
		int lastPos;
		std::vector<double> vecData;

	public:

		// Constructor 
		Vec(int size);

		// Constructor with given data
		Vec(std::vector<double> data);

		// computers the dot product and returns it as a double pointer
		double dot(Vec vector);

		// computes cross product with another vector, must be in R3
		Vec cross(Vec vector);

		// returns magnitude of vector
		double getMag();

		// returns # of elements in vector
		int getSize();

		// gets the unit vector of this vector
		Vec getUnitVec();

		// add two vectors
		Vec add(Vec vector);

		// subtracts two vectors
		Vec sub(Vec vector);

		// remove last element
		void removeLast();

		// Set full vector filled with 1s
		void setOnes();

		// Set full vector filled with 0s
		void setZeros();

		void scale(int scalarMultiple);

		// gets value at pos (1 indexed)
		const double getValue(int pos);

		// returns first value of vector
		const double getFirst();

		// returns last value of vector
		const double getLast();

		// gets the max value in vector
		const double getMax();

		// gets the min value in vector
		const double getMin();

		// returns true if vector is a unit vector
		const bool isUnitVec();

		// computes the project of this vector onto vectorOn
		Vec proj(Vec vectorOn);

		void print(); //needed?

		// apply a function to each element in vector to modify it, fn must take in double and return double
		void apply(std::function<double(double)> fn);

	};

	// 2x1 Transformations (dilation, reflection, rotation)

		// reflect vector over Y-axis
	Matrix refY(Matrix& mat);

	// reflect vector over X-axis
	Matrix refX(Matrix& mat);

	// reflect vector over y=x lines
	Matrix refYX(Matrix& mat);

	// rotate 90 degrees clockwise
	Matrix rot90(Matrix& mat);

	// rotate 180 degrees clockwise
	Matrix rot180(Matrix& mat);

	// rotate 270 degrees clockwise
	Matrix rot270(Matrix& mat);

	// applies 2x2 custom transformation on 2x1 matrix
	Matrix customMatTransform(Matrix& origMat, Matrix& transformMat);

	// Get determinant if a square matrix
	double getDeterminant(Matrix mat);

	// helper to get matrix without row and column
	Matrix getSubMatrix(Matrix& origMatrix, int rowToExclude, int columnToExclude);

	// Creates and returns and Identity matrix of size
	Matrix createIdentity(int size);

	// computes the triple scalar product between 3 vectors
	Vec tripleScalarProduct(Vec vector1, Vec vector2, Vec vector3);

	// Computes the least-squares solution
	// mat must be mxn, vect b must be mx1
	// returns a px1 matrix
	Matrix leastSquares(Matrix mat, Vec b);

}