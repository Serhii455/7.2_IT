#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;


void PrintMatrix(int** A, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << A[i][j];
			cout << endl;
	}
	cout << endl;
}


void MatrixValue(int** A, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = Low + rand() % (High - Low + 1);
		}
}


int FindMin(int** A, const int k, const int n, int& min1, int& min2)
{
	min1 = A[0][0];
	min2 = A[0][0];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			if (j == 2 && A[i][j] < min1)
			{
				min1 = A[i][j];
			}
			else if (j == 4 && A[i][j] < min2) {
				min2 = A[i][j];
			}
	return min2;
}


int MaxAmongMin(int** A, const int k, const int n, int& min1, int& min2)
{ 
	int Max = 0;
	if (min1 > min2)
	{
		Max = min1;
	} else {
		Max = min2;
	}
	return Max;
}


int main()
{
	int Low = 5;
	int High = 25;

	const int k = 5;
	const int n = 5;

	int min1;
	int min2;

	int** A = new int* [k];

	for (int i = 0; i < k; i++)
		A[i] = new int[n];


	MatrixValue(A, k, n, Low, High);

	cout << "Matrix: " << endl;
	PrintMatrix(A, k, n);

	FindMin(A, k, n, min1, min2);
	cout << "MinElement1 = " << min1 << endl;
	cout << "MinElement2 = " << min2 << endl;
	


	int Z = MaxAmongMin(A, k, n, min1, min2);
	cout << "Max Among Min = " << Z << endl;


	for (int i = 0; i < k; i++)
		delete[] A[i];
	delete[] A;


	return 0;
}