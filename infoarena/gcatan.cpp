#include <fstream>
#include <iostream>
using namespace std;

short int n, m, harta[102][102], regiuni, amax;

inline void citire()
{
	char c;
	ifstream fin("catan.in");
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			fin >> c;
			if (c == '0')
				harta[i][j] = 0;
			else
				harta[i][j] = 1;
		}
	}
	fin.close();
}
short int fill(int x, int y)
{
	if (harta[x][y] != 0)
		return 0;
	else
	{
		harta[x][y] = 1;
		return fill(x - 1, y) + fill(x + 1, y) + fill(x, y - 1) + fill(x, y + 1) + 1;
	}
}
inline void rezolvare()
{
	for (int i = 0; i <= n + 1; i++)
	{
		harta[i][0] = 1;
		harta[i][m + 1] = 1;
	}
	for (int i = 0; i <= m + 1; i++)
	{
		harta[0][i] = 1;
		harta[n + 1][i] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (harta[i][j] == 0)
			{
				amax = max(amax, fill(i, j));
				regiuni++;
			}
			
}
inline void scriere()
{
	ofstream fout("catan.out");
	fout << regiuni << '\n' << amax << '\n';
	fout.close();
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

