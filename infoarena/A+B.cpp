/*
 * Autor: Paul Herman
 * Problema: adunarea a doua numere
 * Data: 01.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/adunare
 */
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("adunare.in");
	ofstream fout("adunare.out");
	long long int a, b, s;
	fin >> a >> b;
	s = a + b;
	fout << s;
	fin.close();
	fout.close();
	return 0;
}

