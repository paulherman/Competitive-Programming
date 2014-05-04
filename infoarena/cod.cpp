#include <fstream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

char c[256];
int d[10];
char line[16];
char e[81];
int op, len, eroare, nr, rezultat;
char er[81];
int rlen;

inline void citire()
{
	ifstream fin("cod.in");
	fin.getline(line, 16);
	fin.getline(e, 80);
	fin.close();
}
inline void alfabet()
{
	for (int i = 0; i <= 9; i++)
	{
		c[line[i]] = i + '0';
		d[i] = line[i];
	}
	c[line[10]] = 'p' + 1;
	c[line[11]] = 'p' + 2;
	c[line[12]] = 'p' + 3;
	c[line[13]] = 'p' + 4;
	c[line[14]] = '=';
}
inline void evaluare()
{
	len = strlen(e);
	eroare = 0;
	op = 1;
	rezultat = 0;
	if ((eroare == 0) && ((c[e[0]] < '0') || (c[e[0]] > '9')) && (c[e[0]] != 0))
		eroare = 5;
	for (int i = 0; (i < len) && (eroare == 0); i++)
	{
		if ((eroare == 0) && (i != (len - 1)) && ((c[e[i]] == '=') || (c[e[i]] == 0)))
			eroare = 1;
		if ((eroare == 0) && (i > 0) && ((c[e[i - 1]] < '0') || (c[e[i - 1]] > '9')) && ((c[e[i]] < '0') || (c[e[i]] > '9')))
			eroare = 2;
		if ((eroare == 0) && (op == 4) && (c[e[i]] == '0'))
			eroare = 3;
		if (eroare == 0)
		{
			if ((c[e[i]] < '0') || (c[e[i]] > '9'))
			{
				if (op == 1)
					rezultat += nr;
				else if (op == 2)
					rezultat -= nr;
				else if (op == 3)
					rezultat *= nr;
				else if (op == 4)
					rezultat /= nr;
				op = c[e[i]] - 'p';
				nr = 0;
			}
			else
				nr = nr * 10 + c[e[i]] - '0';
		}
	}
	if ((eroare == 0) && (c[e[len - 1]] != '='))
		eroare = 4;		
}
inline void criptare()
{
	if (eroare == 0)
	{
		rlen = 0;
		while (rezultat > 0)
		{
			er[rlen] = d[rezultat % 10];
			rlen++;
			rezultat /= 10;
		}
	}
}
inline void scriere()
{
	ofstream fout("cod.out");
	if (eroare == 0)
	{
		for (int i = (rlen - 1); i >= 0; i--)
			fout << er[i];
		fout << '\n';
	}
	else
		fout << "eroare " << eroare << '\n';
	fout.close();
}
int main()
{
	citire();
	alfabet();
	evaluare();
	criptare();
	scriere();
	return 0;
}

