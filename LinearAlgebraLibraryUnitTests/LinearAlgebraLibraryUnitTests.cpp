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
	};
}
