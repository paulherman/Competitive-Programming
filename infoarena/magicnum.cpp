/*
 * Autor: Paul Herman
 * Data: 15.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/magicnum
 */
#include <fstream>
using namespace std;

int x, y;
int n;
int divizori[1000001];

int main()
{
	ifstream fin("magicnum.in");
	ofstream fout("magicnum.out");
	fin >> x >> y;
	n = 0;
	for (int i = x; i <= y; i++)
		divizori[i] = 1;
	for (int i = 2; i <= y; i++)
		for (int d = i; d <= y; d += i)
			divizori[d]++;
	for (int i = x; i <= y; i++)
		if (i % divizori[i] == 0)
			n++;
	fout << n;
	fout.close();
	fin.close();
	return 0;
}
