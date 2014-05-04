#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

char a[2000005], b[2000005];
int t[2000005];
vector<int> aparitii;

inline void citire()
{
	ifstream fin("strmatch.in");
	fin.getline(a, 2000005);
	fin.getline(b, 2000005);
	fin.close();
}
inline int min1000()
{
	if (aparitii.size() > 1000)
		return 1000;
	else
		return aparitii.size();
}
inline void scriere()
{
	ofstream fout("strmatch.out");
	fout << aparitii.size() << '\n';
	for (int i = 0; i < min1000(); i++)
		fout << aparitii[i] << ' ';
	fout.close();
}
inline void prefix()
{
	int candidat = 0;
	t[0] = -1;
	t[1] = 0;
	for (int i = 2; (a[i] != 0) && (a[i] != '\n');)
	{
		if (a[i - 1] == a[candidat])
		{
			candidat++;
			t[i] = candidat;
			i++;
		}
		else if (candidat > 0)
			candidat = t[candidat];
		else
		{
			t[i] = 0;
			i++;
		}
	}
}
inline void kmp()
{
	int i = 0; //Pozitia in a
	int m = 0; //Pozitia in b
	while (b[i + m] != 0)
	{
		if (a[i] == b[i + m])
		{
			if ((a[i + 1] == 0) || (a[i + 1] == '\n'))
			{
				aparitii.push_back(m);
				m = m + i - t[i];
				if (t[i] > -1)
					i = t[i];
				else
					i = 0;
			}
			else
				i++;
		}
		else
		{
			m = m + i - t[i];
			if (t[i] > -1)
				i = t[i];
			else
				i = 0;
		}
	}
}
int main()
{
	citire();
	prefix();
	kmp();
	scriere();
	return 0;
}

