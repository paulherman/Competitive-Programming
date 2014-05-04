#include <cstdio>

const int maxn = 100001;
struct edge
{
	int next;
	int to;
};
int FE[maxn], LE[maxn], d[maxn], n, m, s, edges;
edge *E;

void addEdge(int from, int to)
{
	edge e;
	e.next = -1;
	e.to = to;
	if (LE[from] == -1)
	{
		E[edges] = e;
		FE[from] = edges;
		LE[from] = edges;
		edges++;
	}
	else
	{
		E[LE[from]].next = edges;
		E[edges] = e;
		LE[from] = edges;
		edges++;
	}
}
int main()
{
	freopen("bfs.in", "r", stdin):
	freopen("bfs.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &s);
	E = malloc(m * sizeof(edge));
	return 0;
}
