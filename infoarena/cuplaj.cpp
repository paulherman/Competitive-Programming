#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int l, r, m, cuplaj, dist[20001], pereche[20001];
vector<int> g[20001];
const int oo = 0x3f3f3f;

inline void citire()
{
	int a, b;
	freopen("cuplaj.in", "r", stdin);
	scanf("%d %d %d", &l, &r, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		b = b + l;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
inline bool bfs()
{
	queue<int> q;
	int nod = 0;
	for (int i = 1; i <= l; i++)
	{
		dist[i] = oo;
		if (pereche[i] == 0)
		{
			dist[i] = 0;
			q.push(i);
		}
	}
	for (dist[0] = oo; q.empty() == false; q.pop())
	{
		nod = q.front();
		if (nod > 0)
		{
			for (int i = 0; i < g[nod].size(); i++)
			{
				if (dist[pereche[g[nod][i]]] == oo)
				{
					dist[pereche[g[nod][i]]] = dist[nod] + 1;
					q.push(pereche[g[nod][i]]);
				}
			}
		}
	}
	return dist[0] < oo;
}
inline bool dfs(int nod)
{
	if (nod > 0)
	{
		for (int i = 0; i < g[nod].size(); i++)
		{
			if (dist[pereche[g[nod][i]]] == dist[nod] + 1)
			{
				if (dfs(pereche[g[nod][i]]) == true)
				{
					pereche[nod] = g[nod][i];
					pereche[g[nod][i]] = nod;
					return true;
				}
			}
		}
		dist[nod] = oo;
		return false;
	}
	else
		return true;
}
inline void hopcroft_karp()
{
	while (bfs() == true)
		for (int i = 1; i <= l; i++)
			if ((pereche[i] == 0) && (dfs(i) == true))
				cuplaj++;
}
inline void scriere()
{
	freopen("cuplaj.out", "w", stdout);
	printf("%d\n", cuplaj);
	for (int i = 1; i <= l; i++)
		if (pereche[i] > 0)
			printf("%d %d\n", i, (pereche[i] - l));
}
int main()
{
	citire();
	hopcroft_karp();
	scriere();
	return 0;
}
