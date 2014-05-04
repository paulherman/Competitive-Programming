#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, x, y;
vector<int> g[7501], noduri;
int aparitii[7501], dist[2][7501], ndist[2][7501];
queue<int> coada;
const int oo = 0x3f3f3f;

inline void citire()
{
	int a, b;
	ifstream fin("graf.in");
	fin >> n >> m >> x >> y;
	for (int i = 1; i <= m; i++)
	{
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	fin.close();
}
inline void bfs(int s, int p)
{
	for (int i = 1; i <= n; i++)
		dist[p][i] = oo;
	dist[p][s] = 0;
	int nod = s;
	for (coada.push(s); coada.empty() == false; coada.pop())
	{
		nod = coada.front();
		for (int i = 0; i < g[nod].size(); i++)
		{
			if (dist[p][g[nod][i]] > 1 + dist[p][nod])
			{
				dist[p][g[nod][i]] = 1 + dist[p][nod];
				coada.push(g[nod][i]);
			}
		}
	}
}
inline void rezolvare()
{
	bfs(x, 0);
	bfs(y, 1);
	for (int i = 1; i <= n; i++)
	{
		ndist[0][dist[0][i]]++;
		ndist[1][dist[1][i]]++;
	}
	for (int i = 1; i <= n; i++)
		if ((dist[0][i] + dist[1][i] == dist[0][y]) && (ndist[0][dist[0][i]] == 1))
			noduri.push_back(i);
}
inline void scriere()
{
	ofstream fout("graf.out");
	fout << noduri.size() << "\n";
	for (int i = 0; i < noduri.size(); i++)
		fout << noduri[i] << " ";
	fout.close();
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

