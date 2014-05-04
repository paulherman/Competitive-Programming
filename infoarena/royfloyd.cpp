/*
 * Autor: Paul Herman
 * Problema: cautare binara
 * Data: 18.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/royfloyd
 */
#include <fstream>
using namespace std;

int n; //Nr de noduri
int a[101][101]; //Matricea de adiacenta

inline void citire()
{
	ifstream fin("royfloyd.in");
	fin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fin >> a[i][j];
	fin.close();
}
inline void scriere()
{
	ofstream fout("royfloyd.out");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			fout << a[i][j] << ' ';
		fout << '\n';
	}
	fout.close();
}
inline void royfloyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if ((a[i][k] != 0) && (a[k][j] != 0) && (i != j))
					if ((a[i][j] == 0) || ((a[i][k] + a[k][j]) < a[i][j]))
						a[i][j] = a[i][k] + a[k][j];
}
int main()
{
	citire();
	royfloyd();
	scriere();
	return 0;
}

