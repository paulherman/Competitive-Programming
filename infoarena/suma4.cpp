/*
 * Autor: Paul Herman
 * Problema: suma4
 * Data: 17.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/suma4
 */
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int piramida[58][58][58];
int n; //Nr de camere
int m; //Nr de nivele
vector<int> drum; //Drumul parcurs

inline void citire()
{
	ifstream fin("suma4.in");
	fin >> n;
	int camere = 0;
	for (int i = 1; camere < n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= i; k++)
			{
				fin >> piramida[i][j][k];
				camere++;
			}
	fin.close();
}
inline void scriere()
{
	ofstream fout("suma4.out");
	fout << m << ' ' << piramida[1][1][1] << '\n';
	for (int i = 0; i < drum.size(); i++)
		fout << drum[i] << ' ';
	fout.close();
}
inline void nivele()
{
	int sm = 0;
	for (m = 1; sm < n; m++)
		sm += m * m;
	m = m - 1;
}
inline void min4(int nivel, int x, int y)
{
	int a = piramida[nivel + 1][x][y];
	int b = piramida[nivel + 1][x + 1][y];
	int c = piramida[nivel + 1][x][y + 1];
	int d = piramida[nivel + 1][x + 1][y + 1];
	piramida[nivel][x][y] += min(a, min(b, min(c, d)));
}
inline void dinamica()
{
	for (int i = m - 1; i > 0; i--)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= m; k++)
				min4(i, j, k);
}
inline void traseu(int nivel, int x, int y)
{
	drum.push_back((nivel - 1) * nivel * (2 * nivel - 1) / 6 + (y - 1) * nivel + x);
	if (nivel < m)
	{
		int a = piramida[nivel + 1][y][x];
		int c = piramida[nivel + 1][y + 1][x];
		int b = piramida[nivel + 1][y][x + 1];
		int d = piramida[nivel + 1][y + 1][x + 1];
		int minim = min(a, min(b, min(c, d)));
		if (a == minim)
			traseu(nivel + 1, x, y);
		else if (b == minim)
			traseu(nivel + 1, x + 1, y);
		else if (c == minim)
			traseu(nivel + 1, x, y + 1);
		else if (d == minim)
			traseu(nivel + 1, x + 1, y + 1);
	}
}
int main()
{
	citire();
	nivele();
	for (int i = 1; i <= m; i++)
	{
		cout << "nivel " << i << '\n';
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
				cout << piramida[i][j][k] << ' ';
			cout << '\n';
		}
	}
	dinamica();
	for (int i = 1; i <= m; i++)
	{
		cout << "nivel " << i << '\n';
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
				cout << piramida[i][j][k] << ' ';
			cout << '\n';
		}
	}
	traseu(1, 1, 1);
	scriere();
	return 0;
}

