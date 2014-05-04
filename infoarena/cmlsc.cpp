/*
 * Autor: Paul Herman
 * Problema: cel mai lung subsir comun
 * Data: 17.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/cmlsc
 */
#include <fstream>
#include <vector>
using namespace std;

short int n, m; //Lungimile celor doua secvente
short int a[1025], b[1025]; //Cele doua secvente
short int d[1025][1025]; //Matricea pt. dinamica
vector<short int> subsir; //Subsirul comun

inline void cmlsc()
{
	//Bordam matricea pentru dinamica cu 0
	for (short int i = 0; i <= n; i++)
		d[0][i] = 0;
	for (short int i = 0; i <= m; i++)
		d[i][0] = 0;
	//Parcurgem cele doua siruri
	for (short int i = 1; i <= m; i++)
	{
		for (short int j = 1; j <= n; j++)
		{
			if (a[j] == b[i])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	for (short int i = m, j = n; (i > 0) && (j > 0);)
	{
		if (a[j] == b[i])
		{
			subsir.push_back(a[j]);
			i--;
			j--;
		}
		else if (d[i - 1][j] < d[i][j - 1])
			j--;
		else
			i--;
			
	}
}
inline void citire()
{
	ifstream fin("cmlsc.in");
	fin >> n >> m;
	for (short int i = 1; i <= n; i++)
		fin >> a[i];
	for (short int i = 1; i <= m; i++)
		fin >> b[i];
	fin.close();
}
inline void scriere()
{
	ofstream fout("cmlsc.out");
	fout << d[m][n] << '\n';
	while (subsir.empty() == false)
	{
		fout << subsir.back() << ' ';
		subsir.pop_back();
	}
	fout.close();
}
int main()
{
	citire();
	cmlsc();
	scriere();
	return 0;
}

