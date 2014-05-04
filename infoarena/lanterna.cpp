#include <fstream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

const int oo = 0x3f3f3f;
int n, m, k;
int baze[51];
vector<int> g[51];
int cost[51][51], timp[51][51];
int dist[51][1001];

bool relax(int u, int v, int w)
{
	
}
int bf(int w)
{
	queue<int> q;
	int nod;
	for (int i = 0; i <= n; i++)
	{
		dTimp[i] = oo;
		dCost[i] = 0;
	}
	dTimp[1] = 0;
	dCost[1] = w;
	q.push(1);
	while (q.empty() == false)
	{
		nod = q.front();
		q.pop();
		for (unsigned int i = 0; i < g[nod].size(); i++)
			if (relax(nod, g[nod][i], w) == true)
				q.push(g[nod][i]);
	}
}
int main()
{
	freopen("lanterna.in", "r", stdin);
	//freopen("lanterna.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &baze[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c ,d
		scanf("%d %d %d %d", &a, &b, &c, &d);
		cost[a][b] = d;
		cost[b][a] = d;
		timp[a][b] = c;
		timp[b][a] = c;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	return 0;
}

