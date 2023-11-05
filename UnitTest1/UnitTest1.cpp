#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_7.2/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int k = 5;
			const int n = 5;

			int min1, min2;

			int** A = new int* [k];
			for (int i = 0; i < k; i++)
				A[i] = new int[n];

			
			MatrixValue(A, k, n, 5, 25);

			FindMin(A, k, n, min1, min2);

			
			Assert::AreEqual(min1, 5);


			
			for (int i = 0; i < k; i++)
				delete[] A[i];
			delete[] A;
		}
	};
}
