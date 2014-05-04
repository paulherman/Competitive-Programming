/*
 * Autor: Paul Herman
 * Problema: CMMDC
 * Data: 01.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/cmmdc
 */
#include <fstream>
using namespace std;

int main()
{
	unsigned long long int a, b, r;
	ifstream fin("cmmdc.in");
	ofstream fout("cmmdc.out");
	fin >> a >> b;
	if(a == 1 || b == 1)
		fout << "1\n";
	else
		while (b != 0)
		{
			r = b;
			b = a % b;
			a = r;
		}
		if (a == 1)
			fout << "0\n";
		else
			fout << a << "\n";
	fin.close();
	fout.close();
	return 0;
}

