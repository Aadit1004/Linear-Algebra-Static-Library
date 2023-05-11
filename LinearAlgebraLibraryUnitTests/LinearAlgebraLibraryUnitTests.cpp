#include "pch.h"
#include "CppUnitTest.h"
#include <LinearAlgebraLibrary.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearAlgebraLibraryUnitTests
{
	TEST_CLASS(LinearAlgebraLibraryUnitTests)
	{
	public:
		
		TEST_METHOD(MatrixConstructor1Normal)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3, 4); // 3 rows, 4 columns
				Assert::AreEqual(3, testMatrix.getNumRows());
				Assert::AreEqual(4, testMatrix.getNumColumns());
				Assert::IsTrue(testMatrix.allZeros());
			} catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixConstructor1ExceptionCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3, -4);
				Assert::Fail();
			} catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixConstructor1ZeroCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(0, 2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixConstructor2Normal)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4); // 4x4 matrix
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(4, testMatrix.getNumColumns());
				Assert::IsTrue(testMatrix.allZeros());
				Assert::IsTrue(testMatrix.isSquareMatrix());
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixConstructor2ExceptionCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(-4);
				Assert::Fail();
			} catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixConstructor2ZeroCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(0);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}
		TEST_METHOD(MatrixConstructor3SquareMatrix)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::AreEqual(3, testMatrix.getNumRows());
			Assert::AreEqual(3, testMatrix.getNumColumns());
			Assert::IsTrue(testMatrix.isSquareMatrix());
		}

		TEST_METHOD(MatrixConstructor3NonSquareMatrix)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} , {10.0, 11.0, 12.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::AreEqual(4, testMatrix.getNumRows());
			Assert::AreEqual(3, testMatrix.getNumColumns());
			Assert::IsFalse(testMatrix.isSquareMatrix());
		}

		TEST_METHOD(MatrixConstructor3ExceptionCase)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {4.0, 5.0, 6.0}, {7.0, 8.0} , {10.0, 11.0, 12.0} };
			try {
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::Fail();
			} catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixConstructor3oneVecZeroCase)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {} , {7.0, 8.0} , {10.0, 11.0, 12.0} };
			try {
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixConstructor3ZeroCase)
		{
			std::vector<std::vector<double>> testVec{ };
			try {
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixGetNumElemsSquareMatrix)
		{
			LinearAlgebraLibrary::Matrix testMatrix(3);
			Assert::AreEqual(9, testMatrix.getNumElem());
		}

		TEST_METHOD(MatrixGetNumElemsNonSquareMatrix)
		{
			LinearAlgebraLibrary::Matrix testMatrix(2,5);
			Assert::AreEqual(10, testMatrix.getNumElem());
		}

		TEST_METHOD(MatrixGetValueInRange)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(4.0, testMatrix.getValue(1, 0));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixGetValueOutOfRange)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				double test = testMatrix.getValue(-1, 3);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetValueInRange)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(3.0, testMatrix.getValue(0, 2));
				testMatrix.setValue(10.5, 0, 2);
				Assert::AreEqual(10.5, testMatrix.getValue(0, 2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSetValueOutOfRange)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(3.0, testMatrix.getValue(0, 2));
				testMatrix.setValue(10.5, 4, 2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetAllOnes)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.allOnes());
			testMatrix.setOnes();
			Assert::IsTrue(testMatrix.allOnes());
		}

		TEST_METHOD(MatrixSetAllZeros)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.allZeros());
			testMatrix.setZeros();
			Assert::IsTrue(testMatrix.allZeros());
		}

		TEST_METHOD(MatrixSetRandom)
		{
			LinearAlgebraLibrary::Matrix testMatrix(3);
			Assert::IsTrue(testMatrix.allZeros());
			testMatrix.setRandom();
			Assert::IsFalse(testMatrix.allZeros());
		}

		TEST_METHOD(MatrixSetSize1IncorrectDimCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3);
				testMatrix.setSize(-2, 0);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetSize1SetSmallerCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3);
				Assert::AreEqual(3, testMatrix.getNumRows());
				Assert::AreEqual(3, testMatrix.getNumColumns());
				testMatrix.setSize(2, 1);
				Assert::AreEqual(2, testMatrix.getNumRows());
				Assert::AreEqual(1, testMatrix.getNumColumns());
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e1) {
				Assert::Fail();
			}
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3);
				Assert::AreEqual(0.0, testMatrix.getValue(2, 2));
				testMatrix.setSize(2, 1);
				double test = testMatrix.getValue(2, 2);
				Assert::Fail(); // Should not be able to access element after resizing
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e2) {
				// Exception shoild have been caught
			}
		}

		TEST_METHOD(MatrixSetSize1SetLargerCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3);
				Assert::AreEqual(3, testMatrix.getNumRows());
				Assert::AreEqual(3, testMatrix.getNumColumns());
				testMatrix.setSize(4, 5);
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(5, testMatrix.getNumColumns());
				Assert::AreEqual(0.0, testMatrix.getValue(3, 4));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e1) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSetSize2IncorrectDimCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(3);
				testMatrix.setSize(-2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetSize2SquaretoSmallerSquareCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4);
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(4, testMatrix.getNumColumns());
				testMatrix.setSize(2);
				Assert::AreEqual(2, testMatrix.getNumRows());
				Assert::AreEqual(2, testMatrix.getNumColumns());
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4);
				Assert::AreEqual(0.0, testMatrix.getValue(3, 3));
				testMatrix.setSize(2);
				double test = testMatrix.getValue(3, 3);
				Assert::Fail(); // Should not be able to access element after resizing
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e2) {
				// Exception shoild have been caught
			}
		}

		TEST_METHOD(MatrixSetSize2SquaretoLargerSquareCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4);
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(4, testMatrix.getNumColumns());
				testMatrix.setSize(6);
				Assert::AreEqual(6, testMatrix.getNumRows());
				Assert::AreEqual(6, testMatrix.getNumColumns());
				Assert::AreEqual(0.0, testMatrix.getValue(5, 5));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSetSize2NonSquareToSquareCase)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4, 6);
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(6, testMatrix.getNumColumns());
				testMatrix.setSize(5);
				Assert::AreEqual(5, testMatrix.getNumRows());
				Assert::AreEqual(5, testMatrix.getNumColumns());
				Assert::IsTrue(testMatrix.isSquareMatrix());
				Assert::AreEqual(0.0, testMatrix.getValue(4, 4));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4, 6);
				Assert::AreEqual(4, testMatrix.getNumRows());
				Assert::AreEqual(6, testMatrix.getNumColumns());
				testMatrix.setSize(5);
				Assert::AreEqual(5, testMatrix.getNumRows());
				Assert::AreEqual(5, testMatrix.getNumColumns());
				Assert::IsTrue(testMatrix.isSquareMatrix());
				double test = testMatrix.getValue(1, 5);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetIdentityNonSquare)
		{
			LinearAlgebraLibrary::Matrix testMatrix(3, 5);
			Assert::IsFalse(testMatrix.isIdentity());
			testMatrix.setIdentity();
			Assert::AreEqual(3, testMatrix.getNumRows());
			Assert::AreEqual(3, testMatrix.getNumColumns());
			Assert::IsTrue(testMatrix.isSquareMatrix());
			Assert::IsTrue(testMatrix.isIdentity());
		}

		TEST_METHOD(MatrixSetIdentityNormalSquare)
		{
			LinearAlgebraLibrary::Matrix testMatrix(3);
			Assert::IsFalse(testMatrix.isIdentity());
			testMatrix.setIdentity();
			Assert::AreEqual(3, testMatrix.getNumRows());
			Assert::AreEqual(3, testMatrix.getNumColumns());
			Assert::IsTrue(testMatrix.isSquareMatrix());
			Assert::IsTrue(testMatrix.isIdentity());
		}

		TEST_METHOD(MatrixGetLargestValue)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::AreEqual(9.0, testMatrix.getLargestValue());
		}

		TEST_METHOD(MatrixGetSmallestValue)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::AreEqual(1.0, testMatrix.getSmallestValue());
		}

		TEST_METHOD(MatrixGetRankLinInd)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsTrue(testMatrix.isLinearInd());
			Assert::AreEqual(3, testMatrix.getRank());
		}

		TEST_METHOD(MatrixGetRankLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.isLinearInd());
			Assert::AreEqual(2, testMatrix.getRank());
		}

		TEST_METHOD(MatrixGetNullityLinInd)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsTrue(testMatrix.isLinearInd());
			Assert::AreEqual(0, testMatrix.getNullity());
		}

		TEST_METHOD(MatrixGetNullityLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.isLinearInd());
			Assert::AreEqual(1, testMatrix.getNullity());
		}

		TEST_METHOD(MatrixGetColLinInd)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec1);
			std::vector<std::vector<double>> testVec2{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
			Assert::IsTrue(testMatrix.getCol().areEqual(testMatrix2));
		}

		TEST_METHOD(MatrixGetColLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			std::vector<std::vector<double>> testVec2{ {1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
			Assert::IsTrue(testMatrix.getCol().areEqual(testMatrix2));
		}

		TEST_METHOD(MatrixGetNulLinInd)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec1);
			// TO DO
			Assert::IsTrue(false);
		}

		TEST_METHOD(MatrixGetNulLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			// TO DO
			Assert::IsTrue(false);
		}

		TEST_METHOD(MatrixIsVectorRowCase)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}};
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsTrue(testMatrix.isVector());
		}

		TEST_METHOD(MatrixIsVectorColCase)
		{
			std::vector<std::vector<double>> testVec{ {1.0}, {2.0}, {3.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsTrue(testMatrix.isVector());
		}

		TEST_METHOD(MatrixIsVectorFalseCase)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.isVector());
		}

		TEST_METHOD(MatrixIsInvertibleSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(-2.0, getDeterminant(testMatrix));
				Assert::IsTrue(testMatrix.isInvertible());
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixIsInvertibleNonSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				bool testBool = testMatrix.isInvertible();
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixGetTransposeSquareMatrix)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} };
			LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
			std::vector<std::vector<double>> testVec2{ {1.0, 3.0}, {2.0, 4.0} };
			LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
			Assert::IsTrue(testMatrix1.getTranspose().areEqual(testMatrix2));
		}

		TEST_METHOD(MatrixGetTransposeNonSquareMatrix)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
			LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
			std::vector<std::vector<double>> testVec2{ {1.0, 3.0, 5.0}, {2.0, 4.0, 6.0} };
			LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
			Assert::IsTrue(testMatrix1.getTranspose().areEqual(testMatrix2));
		}



















		TEST_METHOD(MatrixGetDeterminantNonSquare)
		{
			try {
				LinearAlgebraLibrary::Matrix testMatrix(4, 5);
				double testDet = getDeterminant(testMatrix);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(MatrixGetDeterminant2x2Square)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(-2.0, getDeterminant(testMatrix));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(MatrixGetDeterminant3x3Square)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(0.0, getDeterminant(testMatrix));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(MatrixGetDeterminant5x5Square)
		{
			try {
				std::vector<std::vector<double>> testVec{ {3.0, 0.0, 0.0, 3.0, 0.0}, {-3.0, 0.0, 2.0, 0.0, 0.0},
					{0.0, -1.0, 0.0, 0.0, -3.0}, {0.0, 0.0, 0.0, 3.0, 3.0}, {0.0, -1.0, 2.0, 0.0, 1.0} };
				LinearAlgebraLibrary::Matrix testMatrix(testVec);
				Assert::AreEqual(-18.0, getDeterminant(testMatrix));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}
	};
}
