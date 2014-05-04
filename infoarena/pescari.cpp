/*
 * Autor: Paul Herman
 * Data: 15.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/pescari
 */
#include <fstream>
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct coord
{
	short int x, y;
	int cost;
};

coord tpct; //Punct folosit pt adaugare
short int n, m; //Dimensiunea matricii
int p; //Nr pescarilor
short teren[1002][1002]; //Labirintul
deque<coord> coada; //Coada pt lee
vector<short int> px, py; //Coordonatele pescarilor

inline void adauga(short int x, short int y, short int cost)
{
	if (teren[x][y] == 0)
	{
		tpct.x = x;
		tpct.y = y;
		tpct.cost = cost;
		teren[x][y] = cost;
		coada.push_back(tpct);
	}
}
inline void citire()
{
	ifstream fin("pescari.in");
	fin >> n >> m >> p;
	for (short i = 1; i <= n; i++)
	{
		for (short j = 1; j <= m; j++)
		{
			fin >> teren[i][j];
			if (teren[i][j] == 2)
			{
				teren[i][j] = 0;
				adauga(i, j, 0);
				teren[i][j] = -2;
			}
			else if (teren[i][j] == 1)
			{
				px.push_back(i);
				py.push_back(j);
				teren[i][j] = 0;
			}
		}
	}
	for (short j = 0; j <= m + 1; j++)
	{
		teren[0][j] = -3;
		teren[n + 1][j] = -3;
	}
	for (short i = 0; i <= n + 1; i++)
	{
		teren[i][0] = -3;
		teren[i][m + 1] = -3;
	}
	fin.close();
}
inline void lee()
{
	coord pct;
	while (coada.empty() == false)
	{
		pct = coada.front();
		coada.pop_front();
		adauga(pct.x - 1, pct.y - 1, pct.cost + 1);
		adauga(pct.x - 1, pct.y, pct.cost + 1);
		adauga(pct.x - 1, pct.y + 1, pct.cost + 1);
		adauga(pct.x, pct.y - 1, pct.cost + 1);
		adauga(pct.x, pct.y + 1, pct.cost + 1);
		adauga(pct.x + 1, pct.y - 1, pct.cost + 1);
		adauga(pct.x + 1, pct.y, pct.cost + 1);
		adauga(pct.x + 1, pct.y + 1, pct.cost + 1);
	}
}
inline void afisare()
{
	ofstream fout("pescari.out");
	for (int k = 0; k < p; k++)
		fout << teren[px[k]][py[k]] << "\n";
	fout.close();
}
int main()
{
	citire();
	lee();
	afisare();
	return 0;
}
