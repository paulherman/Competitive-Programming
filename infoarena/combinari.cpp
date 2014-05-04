/*
 * Autor: Paul Herman
 * Problema: Combinari
 * Data: 05.02.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/combinari
 */
#include <fstream>
#include <iostream>
using namespace std;

int n, k;
int combinare[19];
ofstream fout;

inline void scriere()
{
	for (int i = 1; i <= k; i++)
		fout << combinare[i] << ' ';
	fout << '\n';
}
void bkt(int p)
{
	if (p == k)
		scriere();
	else
	{
		for (int i = combinare[p] + 1; i <= n; i++)
		{
			combinare[p + 1] = i;
			bkt(p + 1);
		}
	}
}
inline void citire()
{
	ifstream fin("combinari.in");
	fin >> n >> k;
	fin.close();
}
int main()
{
	citire();
	fout.open("combinari.out");
	bkt(0);
	fout.close();
}
