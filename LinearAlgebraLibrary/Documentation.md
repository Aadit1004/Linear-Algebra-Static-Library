## **Documentation**
Documentation for all methods for the library. As of right now, only _doubles_ are supported as the matrix and vector data type.

## Matrix Class

### LinearAlgebraLibrary::Matrix Constructor 1

Constructors a Matrix object with a 2 dimension vector a parameter as the given data

Parameters: <br>
data 
: a 2 dimensional vector of doubles. must have at least size 1x1


Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0
```

### LinearAlgebraLibrary::Matrix Constructor 2

Constructors a Matrix object with the given number of rows and columns. Fills all values with 0.0s

Parameters: <br>
m
: # of rows in matrix, must be greater than 0

n
: # of columns in matrix, must be greater than 0


Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Matrix mat(2, 1);
	mat.print();
}
```

Output:
```cpp
0.0
0.0
```

### LinearAlgebraLibrary::Matrix Constructor 2

Constructors a square Matrix object with the given number of rows and columns. Fills all values with 0.0s

Parameters: <br>
n
: # of rows and columns in matrix, must be greater than 0


Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Matrix mat(3);
	mat.print();
}
```

Output:
```cpp
0.0 0.0 0.0
0.0 0.0 0.0
0.0 0.0 0.0
```

### LinearAlgebraLibrary::Matrix setValue

Sets a value in the matrix at the given position

Parameters: <br>
value
: the value that you would like to set

rowNum
: the row number to set the position, 0-indexed

colNum
: the column number to set the position, 0-indexed


Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Matrix mat(3);
	std::cout << mat.getValue(1, 1) << std::endl;
	mat.setValue(3.0, 1, 1);
	std::cout << mat.getValue(1, 1) << std::endl;
}
```

Output:
```cpp
0.0
3.0
```

### LinearAlgebraLibrary::Matrix setOnes

Sets all elements to 1.0 in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setOnes();
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0

1.0 1.0
1.0 1.0
```

### LinearAlgebraLibrary::Matrix setZeros

Sets all elements to 0.0 in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setZeros();
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0

0.0 0.0
0.0 0.0
```

### LinearAlgebraLibrary::Matrix setRandom

Sets all elements to a random double from 0.0 to 100.0 in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Matrix mat(2);
	mat.print();
	mat.setRandom();
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
0.0 0.0
0.0 0.0

22.0 14.0
84.0 12.0
```

### LinearAlgebraLibrary::Matrix setSize 1

Resizes the matrix to the given size, will delete values if row or column decreases and will
add 0.0 as default if row or column increases.

Parameters: <br>
m
: # of rows wanted in matrix

n
: # of columns wanted in matrix

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0} }; // 2x2 matrix
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setSize(1, 3); // set to a 1x3 matrix
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0

1.0 2.0 0.0
```

### LinearAlgebraLibrary::Matrix setSize 1

Resizes the matrix to the given square size, will delete values if row or column decreases and will
add 0.0 as default if row or column increases. 

Parameters: <br>
n
: # of rows and columns wanted in matrix

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0} }; // 2x2 matrix
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setSize(3); // set to a 3x3 matrix
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0

1.0 2.0 0.0
3.0 4.0 0.0
0.0 0.0 0.0
```

### LinearAlgebraLibrary::Matrix setIdentity

Sets *this* Matrix object to a [identity matrix](https://en.wikipedia.org/wiki/Identity_matrix). 
Will set the dimensions to the min of the rows and columns.

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} }; // 3x2 matrix
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setIdentity(); // set to a 3x3 matrix
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0
5.0 6.0

1.0 0.0 
0.0 1.0
```

### LinearAlgebraLibrary::Matrix setUpperTriangle

Sets *this* Matrix object to a [upper triangular matrix](https://mathworld.wolfram.com/UpperTriangularMatrix.html).
Must be a square matrix.

Parameters: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setUpperTriangular();
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0

1.0 2.0 3.0
0.0 5.0 6.0
0.0 0.0 9.0
```

### LinearAlgebraLibrary::Matrix setLowerTriangle

Sets *this* Matrix object to a [upper lower matrix](https://mathworld.wolfram.com/LowerTriangularMatrix.html).
Must be a square matrix.

Parameters: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	mat.setLowerTriangular();
	std::cout << std::endl;
	mat.print();
}
```

Output:
```cpp
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0

1.0 0.0 0.0
4.0 5.0 0.0
7.0 8.0 9.0
```

### LinearAlgebraLibrary::Matrix getValue

Gets the value from the given position param.

Parameters: <br>
rowNum
: the row number from the position, 0-indexed

colNum
: the column number from the position, 0-indexed

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getValue(1, 2); << std::endl;
}
```

Output:
```cpp
6.0
```

### LinearAlgebraLibrary::Matrix getNumElem

Gets the number of elements in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getNumElem(); << std::endl;
}
```

Output:
```cpp
9
```

### LinearAlgebraLibrary::Matrix getNumRows

Gets the number of rows in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getNumRows(); << std::endl;
}
```

Output:
```cpp
3
```

### LinearAlgebraLibrary::Matrix getNumColumns

Gets the number of columns in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getNumColumns(); << std::endl;
}
```

Output:
```cpp
3
```

### LinearAlgebraLibrary::Matrix getLargestValue

Gets the largest number in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getLargestValue(); << std::endl;
}
```

Output:
```cpp
9.0
```

### LinearAlgebraLibrary::Matrix getSmallestValue

Gets the smallest number in the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getSmallestValue(); << std::endl;
}
```

Output:
```cpp
1.0
```

### LinearAlgebraLibrary::Matrix getRow

Gets the row from the matrix

Parameters: <br>
row
: the row to get from the matrix, 0-indexed

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print()
	std::cout << std::endl;
	LinearAlgebraLibrary::Matrix retRow = mat.getRow(1);
	retRow.print();
}
```

Output:
```cpp
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0

4.0 5.0 6.0
```

### LinearAlgebraLibrary::Matrix getColumn

Gets the column from the matrix

Parameters: <br>
column
: the column to get from the matrix, 0-indexed

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} }; 
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print()
	std::cout << std::endl;
	LinearAlgebraLibrary::Matrix retCol = mat.getColumn(0);
	retCol.print();
}
```

Output:
```cpp
1.0 2.0 3.0
4.0 5.0 6.0
7.0 8.0 9.0

1.0
4.0
7.0
```

### LinearAlgebraLibrary::Matrix getRank

Gets the [rank](https://en.wikipedia.org/wiki/Rank_(linear_algebra)) of the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getRank() << std::endl;
}
```

Output:
```cpp
2
```

### LinearAlgebraLibrary::Matrix getNullity

Gets the [nullity](https://www.geeksforgeeks.org/null-space-and-nullity-of-a-matrix/) of the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	std::cout << mat.getNullity() << std::endl;
}
```

Output:
```cpp
1
```

### LinearAlgebraLibrary::Matrix getColSpace

Gets the [column space](https://medium.com/intuitionmath/what-is-column-space-with-a-machine-learning-example-8f8a8d4ec6c) of the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.getColSpace().print();
}
```

Output:
```cpp
1.0 0.0
0.0 1.0
0.0 0.0
```

### LinearAlgebraLibrary::Matrix getNulSpace

Gets the [nul space](https://www.geeksforgeeks.org/null-space-and-nullity-of-a-matrix/) of the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.getNulSpace().print();
}
```

Output:
```cpp
0.0
0.0
0.0
```

### LinearAlgebraLibrary::Matrix getTranspose

Gets the [transpose](https://en.wikipedia.org/wiki/Transpose) of the matrix

Parameters: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} }; // 3x2 matrix
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	std::cout << std::endl;
	LinearAlgebraLibrary::Matrix transposeMat = mat.getTranspose(); // 2x3 matrix
	transposeMat.print();
}
```

Output:
```cpp
1.0 2.0
3.0 4.0
5.0 6.0

1.0 3.0 5.0
2.0 4.0 6.0
```

### LinearAlgebraLibrary::Matrix getInverse

Gets the [inverse](https://en.wikipedia.org/wiki/Invertible_matrix) of the matrix, must be a square matrix

Parameters: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0, 2.0}, {2.0, 3.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	mat.print();
	std::cout << std::endl;
	LinearAlgebraLibrary::Matrix invMat = mat.getInverse(); 
	invMat.print();
}
```

Output:
```cpp
1.0 2.0
2.0 3.0

-3.0 2.0
2.0 -1.0
```

## Vec Class

### LinearAlgebraLibrary::Vec Constructor 1

Constructors a Vec object with a vector a parameter as the given data

Parameters: <br>
data 
: a vector of doubles


Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	std::cout << vec1.getSize() << std::endl;
}
```

Output:
```cpp
3
```

### LinearAlgebraLibrary::Vec Constructor 2

Constructors a Vec object with a given size and fills all vector with 0.0

Parameters: <br>
size
: an int containing desired size, requires size greater than or equal to 0


Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Vec vec1(5);
	std::cout << vec1.getSize() << std::endl;
	std::cout << vec1.allZeros() << std::endl;
}
```

Output:
```cpp
5
1
```

### LinearAlgebraLibrary::Vec setValue

Sets a value in the vector

Parameters: <br>
val
: the value you want to set, must be a double

pos
: the position at which you want to set the value, an int that must be greater than or equal to 0
or less than the size, must be 0-indexed

Return value: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Vec vec1(3);
	std::cout << vec1.getValue(1) << std::endl;
	vec1.setValue(10.0, 1);
	std::cout << vec1.getValue(1) << std::endl;
}
```

Output:
```cpp
0.0
10.0
```

### LinearAlgebraLibrary::Vec setZeros

Sets all values in the Vec object to 0.0

Parameters: <br>
None

Return value: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	vec1.print();
	vec1.setZeros();
	vec1.print();
}
```

Output:
```cpp
1.0, 2.0, 3.0
0.0, 0.0, 0.0
```

### LinearAlgebraLibrary::Vec setOnes

Sets all values in the Vec object to 1.0

Parameters: <br>
None

Return value: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	vec1.print();
	vec1.setOnes();
	vec1.print();
}
```

Output:
```cpp
1.0, 2.0, 3.0
1.0, 1.0, 1.0
```

### LinearAlgebraLibrary::Vec getValue

Gets a value in the vector

Parameters: <br>
pos
: the position at which you want to set the value, an int that must be greater than or equal to 0
or less than the size, must be 0-indexed

Return value: <br>
None

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	std::cout << vec1.getValue(1) << std::endl;
}
```

Output:
```cpp
2.0
```

### LinearAlgebraLibrary::Vec getFirst

Gets the first element in the Vec 

Parameters: <br>
None

Return value: <br>
First element in vector (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	double retVal = vec1.getFirst();
	std::cout << retVal << std::endl;
}
```

Output:
```cpp
1.0
```

### LinearAlgebraLibrary::Vec getLast

Gets the last element in the Vec 

Parameters: <br>
None

Return value: <br>
Last element in vector (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	double retVal = vec1.getLast();
	std::cout << retVal << std::endl;
}
```

Output:
```cpp
3.0
```

### LinearAlgebraLibrary::Vec getMax

Gets the max element in the Vec 

Parameters: <br>
None

Return value: <br>
Max element in vector (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 12.0, 32.0, 8.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	double retVal = vec1.getMax();
	std::cout << retVal << std::endl;
}
```

Output:
```cpp
32.0
```

### LinearAlgebraLibrary::Vec getMin

Gets the min element in the Vec 

Parameters: <br>
None

Return value: <br>
Min element in vector (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp{ 12.0, 32.0, 8.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	double retVal = vec1.getMin();
	std::cout << retVal << std::endl;
}
```

Output:
```cpp
8.0
```

### LinearAlgebraLibrary::Vec getUnitVec

Gets the unit vector of *this* vec object

Parameters: <br>
None

Return value: <br>
Unit vector of *this* Vec (Vec)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	LinearAlgebraLibrary::Vec unitVec = vec1.getUnitVec();
	unitVec.print();
}
```

Output:
```cpp
0.333333, 0.666667, 0.666667
```

### LinearAlgebraLibrary::Vec getSize

Gets the size of Vec object

Parameters: <br>
None

Return value: <br>
Size of vector (int)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	std::cout << vec1.getSize() << std::endl;
}
```

Output:
```cpp
3
```

### LinearAlgebraLibrary::Vec getMag

Gets the magnitude of Vec object

Parameters: <br>
None

Return value: <br>
Magnitude of vector (double)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	std::cout << vec1.getMag() << std::endl;
}
```

Output:
```cpp
3.0
```

### LinearAlgebraLibrary::Vec allZeros

Returns true if all the elements in the Vec object are 0.0

Parameters: <br>
None

Return value: <br>
True if all elements are 0.0, false otherwise (bool)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Vec vec1(5);
	std::cout << vec1.allZeros() << std::endl;
}
```

Output:
```cpp
1
```

### LinearAlgebraLibrary::Vec allOnes

Returns true if all the elements in the Vec object are 1.0

Parameters: <br>
None

Return value: <br>
True if all elements are 1.0, false otherwise (bool)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Vec vec1(5);
	vec1.setOnes();
	std::cout << vec1.allOnes() << std::endl;
}
```

Output:
```cpp
1
```

### LinearAlgebraLibrary::Vec isEmpty

Returns true if there are 0 elements in the vector

Parameters: <br>
None

Return value: <br>
True if the Vec object is empty, false otherwise (bool)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	LinearAlgebraLibrary::Vec vec1(0);
	std::cout << vec1.isEmpty() << std::endl;
}
```

Output:
```cpp
1
```

### LinearAlgebraLibrary::Vec isUnitVec

Returns true if *this* Vec object is a unit vector (where the magnitude equals 1)

Parameters: <br>
None

Return value: <br>
True if the Vec object is a unit vector, false otherwise (bool)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp{ 1.0, 2.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp);
	std::cout << vec1.isUnitVec() << std::endl;
	LinearAlgebraLibrary::Vec unitVec = vec1.getUnitVec();
	std::cout << unitVec.isUnitVec() << std::endl;
}
```

Output:
```cpp
0
1
```

### LinearAlgebraLibrary::Vec areEqual

Returns true if *this* Vec object and given Vec param are equal

Parameters: <br>
vect
: Vec object to compare to *this* Vec object

Return value: <br>
True if the Vec object is equal to given Vec param, false otherwise (bool)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 55.0, 0.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 3.0, 55.0, 0.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	std::cout << vec1.areEqual(vec2) << std::endl;
}
```

Output:
```cpp
1
```

### LinearAlgebraLibrary::Vec copy

Returns copy of *this* Vec object

Parameters: <br>
None

Return value: <br>
Copy of *this* Vec object (Vec)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 5.0, 10.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	LinearAlgebraLibrary::Vec copyVec = vec1.copy();
	copyVec.print();
}
```

Output:
```cpp
3.0, 5.0, 10.0
```

### LinearAlgebraLibrary::Vec add

Returns the sum of *this* Vec object and given Vec param

Parameters: <br>
vector
: Vec object to add to *this* Vec object

Return value: <br>
Sum of the 2 Vec objects (Vec)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 5.0, 10.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 6.0, 1.0, 4.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	LinearAlgebraLibrary::Vec sumVec = vec1.add(vec2);
	sumVec.print();
}
```

Output:
```cpp
9.0, 6.0, 14.0
```

### LinearAlgebraLibrary::Vec sub

Returns the difference of *this* Vec object and given Vec param

Parameters: <br>
vector
: Vec object to subtract to *this* Vec object

Return value: <br>
Difference of the 2 Vec objects (Vec)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 5.0, 10.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 4.0, 2.0, 1.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	LinearAlgebraLibrary::Vec sumVec = vec1.add(vec2);
	sumVec.print();
}
```

Output:
```cpp
-1.0, 3.0, 9.0
```

### LinearAlgebraLibrary::Vec scalar

Multiplies *this* Vec object by a scalar

Parameters: <br>
scalarMultiple
: value that will be multiplied to every element, must be a double

Return value: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 5.0, 10.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	vec1.scalare(2.0);
	vec1.print();
}
```

Output:
```cpp
6.0, 10.0, 20.0
```

### LinearAlgebraLibrary::Vec cross

Takes the [cross product](https://en.wikipedia.org/wiki/Cross_product) of *this* Vec object and given Vec param

Parameters: <br>
vector
: Vec object to take the cross product

Return value: <br>
Cross product of the two vectors (Vec)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 3.0, 2.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 1.0, 3.0, 7.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	LinearAlgebraLibrary::Vec crossVec = vec1.cross(vec2);
	crossVec.print();
}
```

Output:
```cpp
8.0, -19.0, 7.0
```

### LinearAlgebraLibrary::Vec dot

Takes the [dot product](https://en.wikipedia.org/wiki/Dot_product) of *this* Vec object and given Vec param

Parameters: <br>
vector
: Vec object to take the dot product

Return value: <br>
Dot product of the two vectors (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 2.0, 4.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	double dotVal = vec1.dot(vec2);
	std::cout << dotVal << std::endl;
}
```

Output:
```cpp
19.0
```

### LinearAlgebraLibrary::Vec proj3d

Takes the [projection](https://en.wikipedia.org/wiki/Vector_projection) of *this* Vec object onto the given Vec param,
vectors must be in 3 dimension

Parameters: <br>
vector
: Vec object to take the projection on

Return value: <br>
Projection of the two vectors (Vec)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 4.0, 5.0, 6.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	LinearAlgebraLibrary::Vec projVec = vec1.proj3d(vec2);
	projVec.print();
}
```

Output:
```cpp
1.66234, 2.07792, 2.49351
```

### LinearAlgebraLibrary::Vec apply

Applies the given function to each element in the Vec object

Parameters: <br>
fn
: function that takes in double and returns a double

Return value: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp1{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	vec1.apply([](double x) {return x + 2.0;});
	vec1.print();
}
```

Output:
```cpp
3.0, 4.0, 5.0
```

### LinearAlgebraLibrary::Vec print

Prints the elements of the Vec object

Parameters: <br>
None

Return value: <br>
None

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<double> temp1{ 1.0, 2.0, 3.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	vec1.print();
}
```

Output:
```cpp
1.0, 2.0, 3.0
```

### LinearAlgebraLibrary::Vec tripleScalarProduct

Takes the [triple scalar product](https://en.wikipedia.org/wiki/Triple_product) 
between *this* Vec object and the two given Vec params

Parameters: <br>
vector2
: Vec object to take triple scalar product

vector3
: Vec object to take triple scalar product

Return value: <br>
The triple scalar product value (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<double> temp1{ 1.0, 1.0, 2.0 };
	LinearAlgebraLibrary::Vec vec1(temp1);
	std::vector<double> temp2{ 3.0, 1.0, 3.0 };
	LinearAlgebraLibrary::Vec vec2(temp2);
	std::vector<double> temp3{ 1.0, 3.0, 3.0 };
	LinearAlgebraLibrary::Vec vec3(temp3);
	double tcpVal = vec1.tripleScalarProduct(vec2, vc3);
	std::cout << tcpVal << std::endl;
}
```

Output:
```cpp
4.0
```

## Other Methods

### LinearAlgebraLibrary refY

Reflects *this* Matrix object over the y-axis

Parameters: <br>
mat
: Matrix object to reflect over y-axis, must be 2x1 Matrix

Return value: <br>
The same vector Matrix reflected over the y-axis (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = refY(mat);
	retMat.print();
}
```

Output:
```cpp
-1.0
2.0
```

### LinearAlgebraLibrary refX

Reflects *this* Matrix object over the x-axis

Parameters: <br>
mat
: Matrix object to reflect over x-axis, must be 2x1 Matrix

Return value: <br>
The same vector Matrix reflected over the x-axis (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = refX(mat);
	retMat.print();
}
```

Output:
```cpp
1.0
-2.0
```

### LinearAlgebraLibrary refYX

Reflects *this* Matrix object over the y=x line

Parameters: <br>
mat
: Matrix object to reflect over y=x line, must be 2x1 Matrix

Return value: <br>
The same vector Matrix reflected over the y=x line (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = refYX(mat);
	retMat.print();
}
```

Output:
```cpp
2.0
1.0
```

### LinearAlgebraLibrary rot90

Rotates *this* Matrix object 90 degrees counter-clockwise

Parameters: <br>
mat
: Matrix object to rotated 90 degrees, must be 2x1 Matrix

Return value: <br>
The same vector Matrix rotated 90 degrees counter-clockwise (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = rot90(mat);
	retMat.print();
}
```

Output:
```cpp
-2.0
1.0
```

### LinearAlgebraLibrary rot180

Rotates *this* Matrix object 180 degrees counter-clockwise

Parameters: <br>
mat
: Matrix object to rotated 180 degrees, must be 2x1 Matrix

Return value: <br>
The same vector Matrix rotated 180 degrees counter-clockwise (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = rot180(mat);
	retMat.print();
}
```

Output:
```cpp
-1.0
-2.0
```

### LinearAlgebraLibrary rot270

Rotates *this* Matrix object 270 degrees counter-clockwise

Parameters: <br>
mat
: Matrix object to rotated 270 degrees, must be 2x1 Matrix

Return value: <br>
The same vector Matrix rotated 270 degrees counter-clockwise (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix mat(temp);
	LinearAlgebraLibrary::Matrix retMat = rot270(mat);
	retMat.print();
}
```

Output:
```cpp
2.0
-1.0
```

### LinearAlgebraLibrary customMatTransform

Custom transformation on *this* Matrix 

Parameters: <br>
origMat
: Matrix object to transformed, must be 2x1 Matrix

transformMat
: Matrix object representing a transformation, must be 2x2 Matrix

Return value: <br>
The same vector Matrix transformed (Matrix)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> temp{ {1.0}, {2.0} };
	LinearAlgebraLibrary::Matrix origMat(temp);
	std::vector<std::vector<double>> transformVec{ {1.0, 3.0}, {2.0, 5.0} };
	LinearAlgebraLibrary::Matrix transformMat(transformVec);
	LinearAlgebraLibrary::Matrix retMat = customMatTransform(origMat, transformMat);
	retMat.print();
}
```

Output:
```cpp
7.0
12.0
```

### LinearAlgebraLibrary getDeterminant

Gets the [determinant](https://en.wikipedia.org/wiki/Determinant) from *this* Matrix 
using the [Laplace Expansion](https://en.wikipedia.org/wiki/Laplace_expansion) method

Parameters: <br>
mat
: Matrix object to get the determinant, must be a square matrix

Return value: <br>
The determinant of *this* matrix (double)

Throws Exception:  <br>
Yes

Example:
```cpp
int main() {
	std::vector<std::vector<double>> vec1{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
	LinearAlgebraLibrary::Matrix mat(vec1);
	double retVal = getDeterminant(mat);
	std::cout << retVal << std::endl;
}
```

Output:
```cpp
0.0
```

### LinearAlgebraLibrary getSubMatrix

Gets the sub-matrix of a Matrix object without the row and column included as param

Parameters: <br>
origMat
: Matrix object to get the subMatrix from

rowToExclude
: row to exclude from origMatrix

columnToExclude
: column to exclude from origMatrix

Return value: <br>
Matrix without the row and column param (Matrix)

Throws Exception:  <br>
No

Example:
```cpp
int main() {
	std::vector<std::vector<double>> vec1{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
	LinearAlgebraLibrary::Matrix mat(vec1);
	LinearAlgebraLibrary::Matrix retMat = getSubMatrix(mat, 0, 0);
	retMat.print();
}
```

Output:
```cpp
5.0 6.0
8.0 9.0
```