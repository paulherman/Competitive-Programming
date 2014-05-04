#include <fstream>
#include <list>
#include <iostream>
using namespace std;

list<short int> g[10001];
short int cost[10001], heap[10001];
short int n, k, cost_total, heap_size;

inline void citire()
{
	short int a, b;
	ifstream fin("cezar.in");
	fin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	fin.close();
}
inline void heap_swap(int a, int b)
{
	short int t = heap[a];
	heap[a] = heap[b];
	heap[b] = t;
}
inline bool heap_compare(int a, int b)
{
	a = heap[a];
	b = heap[b];
	return cost[a] + g[a].size() > cost[b] + g[b].size();
}
inline void heap_down(int x)
{
	bool modificat = false;
	short int fius, fiud, mic;
	do {
		mic = x;
		fius = 2 * x + 1;
		fiud = fius + 1;
		if ((fius < heap_size) && (heap_compare(mic, fius) == true))
			mic = fius;
		if ((fiud < heap_size) && (heap_compare(mic, fiud) == true))
			mic = fiud;
		modificat = false;
		if (mic != x)
		{
			modificat = true;
			heap_swap(x, mic);
			x = mic;
		}
	} while (modificat == true);
}
inline short int heap_pop()
{
	short int heap_top = heap[0];
	heap_size--;
	heap[0] = heap[heap_size];
	heap_down(heap[0]);
	return heap_top;
}
inline void heap_push(int x)
{
	heap[heap_size] = x;
	heap_size++;
	x = heap_size;
	int tata = (x - 1) / 2;
	while (heap_compare(tata, x) == true)
	{
		heap_swap(tata, x);
		x = tata;
		tata = (x - 1) / 2;
	}
}
inline void rezolvare()
{
	short int nod = 0;
	short int noduri_ramase = n;
	for (int i = 1; i <= n; i++)
	{
		cost[i] = 1;
		if (g[i].size() == 1)
			heap_push(i);
	}
	for (int i = 0; i < heap_size / 2; i++)
		heap_down(i);
	while (noduri_ramase > k + 1)
	{
		noduri_ramase--;
		nod = heap_pop();
		cost_total += cost[nod];
		for (list<short int>::iterator i = g[nod].begin(); i != g[nod].end(); i++)
		{
			cost[*i] += cost[nod];
			g[*i].remove(nod);
			if (g[*i].size() == 1)
				heap_push(*i);
		}
		g[nod].clear();
		for (int i = 0; i < heap_size / 2; i++)
			heap_down(i);
		cout << nod << ": ";
		for (int i = 0; i < heap_size; i++)
			cout << "(" << heap[i] << "-" << cost[heap[i]] << ") ";
		cout << '\n';
	}
}
inline void scriere()
{
	ofstream fout("cezar.out");
	fout << cost_total << '\n';
	fout.close();
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

