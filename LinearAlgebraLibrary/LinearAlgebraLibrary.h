// LinearAlgebraLibrary.h
#pragma once
#include <vector>

namespace LinearAlgebraLibrary {

	class Matrix {

		int rows;
		int columns;
		std::vector<std::vector<double*>> matrixData;

	public:

		// Constructor
		Matrix(int m, int n);

		// Constructor for Square Matrix
		Matrix(int n);

		// Constructor with given values
		Matrix(std::vector<std::vector<double*>> data);

		// Get value from pos
		const double* getValue(int rowNum, int colNum);

		// get number of elements in matrix
		const int getNumElem();

		// Set value at pos
		void setValue(double* value, int rowNum, int colNum);

		// Set full matrix filled with 1s
		void setOnes();

		// Set full matrix filled with 0s
		void setZeros();

		// Set full matrix filled with random integers
		void setRandom();

		// Resize matrix to new dimensions, if larger->new values are 0s
		void setSize(int m, int n);

		// Resize matrix to square size
		void setSize(int n);

		// Sets matrix to identity matrix to size of lower dim
		void setIdentity();

		// Get number of rows
		const int getRows();

		// Get number of columns
		const int getColumns();

		// Get determinant if a square matrix
		const int getDeterminant();

		// Returns largest value in matrix
		const int getLargestValue();

		// returns smallest value in matrix
		const int getSmallestValue();

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

		// Is matrix diagonalizable
		const bool isDiagonalizable();

		// Returns true if matrix rows are linearly independent, false otherwise
		const bool isLinearInd();

		// returns true if matrix is a row or column vector, false otherwise
		const bool isVector();

		// returns true if square matrix and columns are lin ind
		const bool isInvertible();

		// Get transpose of matrix
		Matrix getTranspose();

		// Get inverse of matrix
		Matrix getInverse();

		// Return the addition from this matrix and mat if possible
		Matrix add(Matrix mat);

		// Return the subtraction from this matrix and mat if possible
		Matrix sub(Matrix mat);

		// Return the multiplication from this matrix and mat if possible
		Matrix mul(Matrix mat);

		// Compute and return the Row Echelon Form of the matrix
		Matrix ref();

		// Compute and return the Reduced Row Echelon Form of the matrix
		Matrix rref();

		// Print the Matrix (cout)
		void print(); //needed?


		// 2x1 Transformations (dilation, reflection, rotation)

		// reflect vector over Y-axis
		Matrix refY();

		// reflect vector over X-axis
		Matrix refX();

		// reflect vector over y=x lines
		Matrix refYX();

		// rotate 90 degrees clockwise
		Matrix rot90();

		// rotate 180 degrees clockwise
		Matrix rot180();

		// rotate 270 degrees clockwise
		Matrix rot270();

	};

	Matrix createIdentity(int size);

	class Vec {

		int size;
		std::vector<double*> vecData;

	public:

		// Constructor 
		Vec(int size);

		// Constructor with given data
		Vec(std::vector<double*> data);

		double* dot(Vec vector);

		Vec cross(Vec vector);

		double getMag();

		Vec getUnitVec();

		Vec add(Vec vector);

		Vec sub(Vec vector);

		double* getValue(int pos);

		double* getFirst();

		double* getLast();

		double* getMax();

		double* getMin();

		void print(); //needed?

	};

}