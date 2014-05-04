#include <fstream>
#include <iostream>
using namespace std;

int n, p[100002];
long long int s, si;

int main()
{
	ifstream fin("bursa.in");
	ofstream fout("bursa.out");
	fin >> n >> si;
	s = si;
	for (int i = 1; i <= n; i++)
		fin >> p[i];
	p[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		if (p[i] < p[i + 1])
			s = (s % p[i]) + (s / p[i]) * p[i + 1];
	fout << s - si << '\n';
	fout.close();
	fin.close();
	return 0;
}

