/*
 * Autor: Paul Herman
 * Data: 15.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/crescator
 */
#include <fstream>
using namespace std;

int n;
long int x, xp;
int lungime;
int lmax;
int siruri;

#define INFINIT 2000000001

int main()
{
	ifstream fin("crescator.in");
	ofstream fout("crescator.out");
	fin >> n;
	xp = INFINIT;
	lungime = 0;
	lmax = 0;
	siruri = 0;
	do {
		fin >> x;
		if (x < xp)
		{
			siruri += lungime * (lungime + 1) / 2;
			if (lungime > lmax)
				lmax = lungime;
			lungime = 0;
		}
		lungime++;
		xp = x;
		n--;
	} while (n > 0);
	siruri += lungime * (lungime + 1) / 2;
	if (lungime > lmax)
		lmax = lungime;
	fout << siruri << " " << lmax;
	fout.close();
	fin.close();
	return 0;
}
