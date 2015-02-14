/*
 * Autor: Paul Herman
 * Problema: APM - Prim
 * Data: 06.02.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/apm
 */
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

#define oo 0x3f3f3f

vector< pair<int, int> > g[200001], apm;
int p[200001], h[200001], dist[200001], vecin[200001], dh, cost_apm, n, m;
/* dh = heap size
 * p[node] = index of node in heap
 * h[x] = node id
 * vecin[node] = parintele nodului */

inline void heap_swap(int a, int b)
{
	swap(h[a], h[b]);
	p[h[a]] = a;
	p[h[b]] = b;
}
inline void heap_up(int x)
{
	int tata = (x - 1) / 2;
	while ((tata != x) && (dist[h[x]] < dist[h[tata]]))
	{
		heap_swap(x, tata);
		x = tata;
		tata = (x - 1) / 2;
	}
}
inline void heap_pop()
{
	dh--;
	p[h[dh]] = 0;
	p[h[0]] = -1;
	h[0] = h[dh];
	int mic = 0;
	int modificat;
	int fius, fiud;
	do {
		modificat = mic;
		fius = 2 * modificat + 1;
		fiud = fius + 1;
		if ((fius < dh) && (dist[h[fius]] < dist[h[mic]]))
			mic = fius;
		if ((fiud < dh) && (dist[h[fiud]] < dist[h[mic]]))
			mic = fiud;
		heap_swap(mic, modificat);
	} while (mic != modificat);
}
inline int heap_top()
{
	int top = h[0];
	heap_pop();
	return top;
}
inline void heap_push(int x)
{
	h[dh] = x;
	p[x] = dh;
	dh++;
	heap_up(p[x]);
}
inline void nod_apm(int x)
{
	apm.push_back(pair<int, int>(x, vecin[x]));
	cost_apm += dist[x];
	for (int i = 0; i < g[x].size(); i++)
	{
		if (dist[g[x][i].first] > g[x][i].second)
		{
			dist[g[x][i].first] = g[x][i].second;
			vecin[g[x][i].first] = x;
			if (p[g[x][i].first] != -1)
				heap_up(p[g[x][i].first]);
		}
	}
}
inline void prim(int s)
{
	for (int i = 2; i <= n; i++)
	{
		p[i] = -1;
		dist[i] = oo;
		vecin[i] = 0;
		heap_push(i);
	}
	dist[s] = 0;
	vecin[s] = 0;
	for (int i = 0; i < g[s].size(); i++)
	{
		if (dist[g[s][i].first] > g[s][i].second)
		{
			dist[g[s][i].first] = g[s][i].second;
			vecin[g[s][i].first] = s;
			heap_up(p[g[s][i].first]);
		}
	}
	for (int mi = 1; mi < n; mi++)
		nod_apm(heap_top());
}
int main() {
	freopen("apm.in", "r", stdin);
	freopen("apm.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	for (int i = 2; i <= n; i++) {
		heap_id[i] = -1;
		d[i] = infty;
		p[i] = 0;
		heap_push(i);
	}
	d[1] = 0;
	p[1] = 0;


	printf("%d\n%d\n", mst_weight, mst.size());
	for (int i = 0; i < (int)mst.size(); i++)
		printf("%d %d\n", mst[i].first, mst[i].second);

	return 0;
}

