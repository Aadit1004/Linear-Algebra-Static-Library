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
	};
}
