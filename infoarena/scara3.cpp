#include <fstream>
#include <iostream>
using namespace std;

short int pasi[1201], cost[1201], apa[1201], suc[1201], n, na, ns;

inline void citire()
{
	short int p, c;
	ifstream fin("scara3.in");
	fin >> n;
	fin >> na;
	for (short int i = 0; i < na; i++)
	{
		fin >> p >> c;
		apa[p] = c;
	}
	fin >> ns;
	for (short int i = 0; i < ns; i++)
	{
		fin >> p >> c;
		suc[p] = c;
	}
	fin.close();
}
inline void scriere()
{
	ofstream fout("scara3.out");
	fout << pasi[n] << " " << cost[n];
	fout.close();
}
inline void rezolvare()
{
	for (short int i = 0; i <= n; i++)
	{
		pasi[i] = 30000;
		cost[i] = 30000;
	}
	pasi[0] = 0;
	cost[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		//Daca bea apa
		if (apa[i] > 0)
		{
			for (int j = 1; j <= apa[i]; j++)
			{
				if (pasi[i + j] >= pasi[i] + 1)
				{
					if ((cost[i + j] > cost[i]) || (pasi[i + j] > pasi[i] + 1))
	 					cost[i + j] = cost[i];
					pasi[i + j] = pasi[i] + 1;
				}
			}
		}
		//Daca bea suc
		if (suc[i] > 0)
		{
			for (int j = 1; j <= 2 * suc[i]; j++)
			{
				if (pasi[i + j] >= pasi[i] + 1)
				{
					if ((cost[i + j] > (cost[i] + (j + 1) / 2)) || (pasi[i + j] > pasi[i] + 1))
						cost[i + j] = cost[i] + (j + 1) / 2;
					pasi[i + j] = pasi[i] + 1;
				}
			}
		}
		//Daca nu bea nimic
		if (pasi[i + 1] >= pasi[i] + 1)
		{
			if ((pasi[i + 1] > pasi[i] + 1) || (cost[i + 1] > cost[i]))
				cost[i + 1] = cost[i];
			pasi[i + 1] = pasi[i] + 1;
		}
	}
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

