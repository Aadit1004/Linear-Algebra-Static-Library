#pragma once
#include "vector"

class Matrix
{
	int rows = 0;
	int columns = 0;

	// data can be float, double, (unsigned) short, int, long
	std::vector<std::vector<void*>> matrixData;

public:

	Matrix(int m, int n);
	void* getValue(int rowNum, int colNum);
};

# **Aadit's C++ Linear Algebra Static Library**