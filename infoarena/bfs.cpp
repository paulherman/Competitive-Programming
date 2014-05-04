/*
 * Autor: Paul Herman
 * Problema: parcurgere in latime
 * Data: 01.03.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/bfs
 */
#include <fstream>
#include <queue>
using namespace std;

int n, m, s;
int dist[100001];
vector<int> g[100001];
queue<int> q;

inline void citire()
{
	int a, b;
	ifstream fin("bfs.in");
	fin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		fin >> a >> b;
		g[a].push_back(b);
	}
	fin.close();
}
inline void scriere()
{
	ofstream fout("bfs.out");
	for (int i = 1; i <= n; i++)
		if (dist[i] < 0x3f3f3f)
			fout << dist[i] << ' ';
		else
			fout << "-1 ";
	fout.close();
}
inline void bfs()
{
	int nod = 0;
	for (int i = 1; i <= n; i++)
		dist[i] = 0x3f3f3f;
	dist[s] = 0;
	for (q.push(s); q.empty() == false; q.pop())
	{
		nod = q.front();
		for (int i = 0; i < g[nod].size(); i++)
		{
			if (dist[g[nod][i]] > dist[nod] + 1)
			{
				dist[g[nod][i]] = dist[nod] + 1;
				q.push(g[nod][i]);
			}
		}
	}
}
int main()
{
	citire();
	bfs();
	scriere();
	return 0;
}

