#include <iostream>
#include <cstring>
using namespace std;

#define NMAX 100

void print_matrix(double matrix[NMAX][NMAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << ' ';
		cout << "\n";
	}
}
double det(double matrix[NMAX][NMAX], int n)
{
	double determinant = 0;
	double nmatrix[NMAX][NMAX];
	if (n > 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					nmatrix[j][k] = 0.0;
			for (int k = 1; k < n; k++)
			{
				for (int j = 0; j < i; j++)
					nmatrix[k - 1][j] = matrix[k][j];
				for (int j = i + 1; j < n; j++)
					nmatrix[k - 1][j - 1] = matrix[k][j];
			}
			if (i % 2 == 0)
				determinant += matrix[0][i] * det(nmatrix, n - 1);
			else
				determinant -= matrix[0][i] * det(nmatrix, n - 1);
		}
	}
	else if (n == 2)
		determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else if (n == 1)
		determinant = matrix[0][0];
	return determinant;
}
int main()
{
	double matrix[NMAX][NMAX];
	int n = 0;
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	cout << "det = " << det(matrix, n) << "\n";
	return 0;
}

