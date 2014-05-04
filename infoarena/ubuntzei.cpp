/*
 * Autor: Paul Herman
 * Problema: ubuntzei
 * Data: 14.10.2011
 * Punctaj: -
 * Link: http://www.infoarena.ro/problema/ubuntzei
 */
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#define oo 0x3f3f3f

int n, m, k;
int ns[17];
vector<int> graf[2001];
vector<int> cost[2001];
int dist[17][2001];
int distanta;

inline void citire()
{
	int a, b, c;
	ifstream fin("ubuntzei.in");
	fin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
		fin >> ns[i];
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b >> c;
		graf[a].push_back(b);
		graf[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	fin.close();
}
inline void bellman_ford(int p, int s)
{
	bool relaxare = true;
	for (int i = 1; i <= n; i++)
		dist[p][i] = oo;
	dist[p][s] = 0;
	for (int i = 1; (i <= n) && (relaxare == true); i++)
	{
		relaxare = false;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < graf[j].size(); k++)
			{
				if (dist[p][graf[j][k]] > (dist[p][j] + cost[j][k]))
				{
					dist[p][graf[j][k]] = dist[p][j] + cost[j][k];
					relaxare = true;
				}
			}
		}
	}
}
inline void rezolvare()
{
	ns[0] = 1;
	ns[k + 1] = n;
	for (int i = 0; i <= k; i++)
		bellman_ford(i, ns[i]);
	distanta = oo;
}
inline void scriere()
{
	ofstream fout("ubuntzei.out");
	fout << distanta << '\n';
	fout.close();
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

