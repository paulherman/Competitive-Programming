/*
 * Autor: Paul Herman
 * Problema: arbori de intervale
 * Data: 26.02.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/arbint
 */
#include <fstream>
#include <iostream>
using namespace std;

int v[500000];
int n, m;
int q, a, b;

int query(int nod, int s, int d)
{
	if ((a <= s) && (d <= b))
		return v[nod];
	else
	{
		int m = (s + d) / 2;
		int r = -1;
		if (a <= m)
			r = max(r, query(2 * nod, s, m));
		if (m < b)
			r = max(r, query(2 * nod + 1, m + 1, d));
		return r;
	}
}
void update(int nod, int s, int d)
{
	if (s == d)
		v[nod] = b;
	else
	{
		int m = (s + d) / 2;
		if (a <= m)
			update(2 * nod, s, m);
		else
			update(2 * nod + 1, m + 1, d);
		v[nod] = max(v[2 * nod], v[2 * nod + 1]);
	}
}
int main()
{
	ifstream fin("arbint.in");
	ofstream fout("arbint.out");
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fin >> b;
		a = i;
		update(1, 1, n);
	}
	for (int i = 1; i <= m; i++)
	{
		fin >> q >> a >> b;
		if (q == 0)
			fout << query(1, 1, n) << '\n';
		else
			update(1, 1, n);
	}
	fin.close();
	fout.close();
	return 0;
}

