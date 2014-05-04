/*
 * Autor: Paul Herman
 * Problema: generare permutari
 * Data: 17.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/permutari
 */
#include <fstream>
using namespace std;

ofstream fout;
short int n;
int permutare[9];

inline void citire()
{
	ifstream fin("permutari.in");
	fin >> n;
	fin.close();	
}
inline void scriere()
{
	for (int i = 0; i < n; i++)
		fout << permutare[i] << ' ';
	fout << '\n';
}
inline bool verificare(int k, int v)
{
	for (int i = 0; i < k; i++)
		if (permutare[i] == v)
			return false;
	return true;
}
void backtracking(int k)
{
	if (k == n)
		scriere();
	else
	{
		//Parcurgem toate valorile posibile
		for (int i = 1; i <= n; i++)
		{
			if (verificare(k, i) == true)
			{
				permutare[k] = i;
				backtracking(k + 1);
			}
		}
	}
}
int main()
{
	citire();
	fout.open("permutari.out");
	backtracking(0);
	fout.close();
	return 0;
}

