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
			Assert::IsTrue(testMatrix.getColSpace().areEqual(testMatrix2));
		}

		TEST_METHOD(MatrixGetColLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			std::vector<std::vector<double>> testVec2{ {1.0, 0.0}, {0.0, 1.0}, {0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
			Assert::IsTrue(testMatrix.getColSpace().areEqual(testMatrix2));
		}

		TEST_METHOD(MatrixGetNulLinInd)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec1);
			// TO DO
			Assert::Fail();
		}

		TEST_METHOD(MatrixGetNulLinDep)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			// TO DO
			Assert::Fail();
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
			std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::AreEqual(-2.0, getDeterminant(testMatrix));
			Assert::IsTrue(testMatrix.isInvertible());
	
		}

		TEST_METHOD(MatrixIsInvertibleNonSquareMatrix)
		{
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			Assert::IsFalse(testMatrix.isInvertible());
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

		TEST_METHOD(MatrixAddDifferentDim)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {1.0, 3.6}, {3.8, 24.2} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix test = testMatrix1.add(testMatrix2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
			
			
		}

		TEST_METHOD(MatrixAddSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {5.0, 6.0}, {7.0, 8.0} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.add(testMatrix2);
				std::vector<std::vector<double>> retVec{ {6.0, 8.0}, {10.0, 12.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixAddNonSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {1.0, 3.6}, {3.8, 24.2}, {256.5, -44.2} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.add(testMatrix2);
				std::vector<std::vector<double>> retVec{ {2.0, 5.6}, {6.8, 28.2}, {261.5, -38.2} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSubDifferentDim)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {1.0, 3.6}, {3.8, 24.2} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix test = testMatrix1.sub(testMatrix2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}


		}

		TEST_METHOD(MatrixSubSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {-3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {15.3, -3.6}, {3.8, 24.2} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.sub(testMatrix2);
				std::vector<std::vector<double>> retVec{ {-14.3, 5.6}, {-6.8, -20.2} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSubNonSquareMatrix)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {10.0, 10.0}, {10.0, 10.0}, {10.0, 10.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {1.0, 3.0}, {7.0, 2.0}, {9.0, 0.0} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.sub(testMatrix2);
				std::vector<std::vector<double>> retVec{ {9.0, 7.0}, {3.0, 8.0}, {1.0, 10.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixMulIncorrectDimCase)
		{
			// m x n * m x n
			try {
				std::vector<std::vector<double>> testVec1{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.mul(testMatrix2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
			
		}

		TEST_METHOD(MatrixMulBothSquare)
		{
			// n x n * n x n
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} }; // 2 x 2
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {5.0, 6.0}, {7.0, 8.0} }; // 2 x 2
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.mul(testMatrix2);
				std::vector<std::vector<double>> retVec{ {19.0, 22.0}, {43.0, 50.0}};
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixMulNotSquare)
		{
			// m x n * n x p
			try {
				std::vector<std::vector<double>> testVec1{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				std::vector<std::vector<double>> testVec2{ {3.0, 4.0} }; // 1 x 2
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.mul(testMatrix2);
				std::vector<std::vector<double>> retVec{ {3.0, 4.0}, {6.0, 8.0} }; // 2 x 2
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(testRet.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixPowerNonSquare)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.power(2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixPowerZero)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.power(0);
				Assert::IsTrue(testRet.isIdentity());
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixPowerGreaterThanZero)
		{
			try {
				std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
				LinearAlgebraLibrary::Matrix testRet = testMatrix1.power(2);
				std::vector<std::vector<double>> testVec2{ {7.0, 10.0}, {15.0, 22.0} };
				LinearAlgebraLibrary::Matrix testMatrix2(testVec2);
				Assert::IsTrue(testRet.areEqual(testMatrix2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixApplyFn)
		{
			std::vector<std::vector<double>> testVec1{ {1.0, 2.0}, {3.0, 4.0} };
			LinearAlgebraLibrary::Matrix testMatrix1(testVec1);
			testMatrix1.apply([](double x) {return pow(x, 2);});
			std::vector<std::vector<double>> retVec{ {1.0, 4.0}, {9.0, 16.0} };
			LinearAlgebraLibrary::Matrix retMat(retVec);
			Assert::IsTrue(testMatrix1.areEqual(retMat));
		}

		TEST_METHOD(MatrixRefLinIndSquare)
		{
			// 3 x 3
			std::vector<std::vector<double>> testVec{ {0.0, -1.0, -4.0}, {2.0, 4.0, 6.0}, {3.0, 0.0, -1.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			testMatrix.ref();
			std::vector<std::vector<double>> retVec{ {2.0, 4.0, 6.0}, {0.0, -1.0, -4.0}, {0.0, 0.0, 14.0} };
			LinearAlgebraLibrary::Matrix retMat(retVec);
			Assert::IsTrue(testMatrix.areEqual(retMat));
			Assert::IsTrue(testMatrix.isLinearInd());
		}

		TEST_METHOD(MatrixRefLinIndNonSquare)
		{
			// 3 x 2
			std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {4.0, 3.0}, {5.0, 6.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			testMatrix.ref();
			std::vector<std::vector<double>> retVec{ {1.0, 2.0}, {0.0, -5.0}, {0.0, 0.0} };
			LinearAlgebraLibrary::Matrix retMat(retVec);
			Assert::IsTrue(testMatrix.areEqual(retMat));
			Assert::IsTrue(testMatrix.isLinearInd());
		}

		TEST_METHOD(MatrixRefLinDepSquare)
		{
			// 3 x 3
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			testMatrix.ref();
			std::vector<std::vector<double>> retVec{ {1.0, 2.0, 3.0}, {0.0, -3.0, -6.0}, {0.0, 0.0, 0.0} };
			LinearAlgebraLibrary::Matrix retMat(retVec);
			Assert::IsTrue(testMatrix.areEqual(retMat));
			Assert::IsFalse(testMatrix.isLinearInd());
		}

		TEST_METHOD(MatrixRefLinDepNonSquare)
		{
			// 2 x 3
			std::vector<std::vector<double>> testVec{ {1.0, 2.0, 2.0}, {4.0, 3.0, 3.0} };
			LinearAlgebraLibrary::Matrix testMatrix(testVec);
			testMatrix.ref();
			std::vector<std::vector<double>> retVec{ {1.0, 2.0, 2.0}, {0.0, -5.0, -5.0} };
			LinearAlgebraLibrary::Matrix retMat(retVec);
			Assert::IsTrue(testMatrix.areEqual(retMat));
			Assert::IsFalse(testMatrix.isLinearInd());
		}

		TEST_METHOD(MatrixSetUpperTriangleNonSquare)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				testMat.setUpperTriangular();
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetUpperTriangleNormal)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				Assert::IsFalse(testMat.isTriangularMatrix());
				testMat.setUpperTriangular();
				Assert::IsTrue(testMat.isTriangularMatrix());
				std::vector<std::vector<double>> testVec2{ {1.0, 2.0, 3.0}, {0.0, 5.0, 6.0}, {0.0, 0.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat2(testVec2);
				Assert::IsTrue(testMat.areEqual(testMat2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixSetLowerTriangleNonSquare)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				testMat.setLowerTriangular();
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixSetLowerTriangleNormal)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				Assert::IsFalse(testMat.isTriangularMatrix());
				testMat.setLowerTriangular();
				Assert::IsTrue(testMat.isTriangularMatrix());
				std::vector<std::vector<double>> testVec2{ {1.0, 0.0, 0.0}, {5.0, 5.0, 0.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat2(testVec2);
				Assert::IsTrue(testMat.areEqual(testMat2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixGetRowExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = testMat.getRow(-2);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixGetRowNormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = testMat.getRow(2);
				std::vector<std::vector<double>> testVec2{ {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat2(testVec2);
				Assert::IsTrue(test.areEqual(testMat2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}

		TEST_METHOD(MatrixGetColumnExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = testMat.getColumn(-3);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}
		}

		TEST_METHOD(MatrixGetColumnNormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = testMat.getColumn(1);
				std::vector<std::vector<double>> testVec2{ {2.0}, {5.0}, {8.0} };
				LinearAlgebraLibrary::Matrix testMat2(testVec2);
				Assert::IsTrue(test.areEqual(testMat2));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}
		}


















		TEST_METHOD(RefYExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refY(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(RefYNormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refY(testMat);
				std::vector<std::vector<double>> retVec{ {-1.0}, {2.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(RefXExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refX(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(RefXNormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refX(testMat);
				std::vector<std::vector<double>> retVec{ {1.0}, {-2.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(RefYXExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refYX(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(RefYXNormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = refYX(testMat);
				std::vector<std::vector<double>> retVec{ {2.0}, {1.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(Rot90ExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot90(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(Rot90NormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot90(testMat);
				std::vector<std::vector<double>> retVec{ {-2.0}, {1.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(Rot180ExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot180(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(Rot180NormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot180(testMat);
				std::vector<std::vector<double>> retVec{ {-1.0}, {-2.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}

		TEST_METHOD(Rot270ExceptionCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0, 2.0}, {3.0, 4.0} };
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot270(testMat);
				Assert::Fail();
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				// Exception should have been caught
			}

		}

		TEST_METHOD(Rot270NormalCase)
		{
			try {
				std::vector<std::vector<double>> testVec{ {1.0}, {2.0} }; // 2 x 1
				LinearAlgebraLibrary::Matrix testMat(testVec);
				LinearAlgebraLibrary::Matrix test = rot270(testMat);
				std::vector<std::vector<double>> retVec{ {2.0}, {-1.0} };
				LinearAlgebraLibrary::Matrix retMat(retVec);
				Assert::IsTrue(test.areEqual(retMat));
			}
			catch (LinearAlgebraLibrary::LinearAlgebraLibException e) {
				Assert::Fail();
			}

		}
		TEST_METHOD(GetDeterminantNonSquare)
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

		TEST_METHOD(GetDeterminant2x2Square)
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

		TEST_METHOD(GetDeterminant3x3Square)
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

		TEST_METHOD(GetDeterminant5x5Square)
		{
			try {
				std::vector<std::vector<double>> testVec{ {3.0, 0.0, 0.0, 3.0, 0.0}, {-3.0, 0.0, -2.0, 0.0, 0.0},
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
