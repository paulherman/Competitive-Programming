/*
 * Autor: Paul Herman
 * Problema: multimi disjuncte
 * Data: 14.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/disjoint
 */
#include <fstream>
using namespace std;

int tati[100001]; //Vector ce contine tatii fiecarui nod
int inaltime[100001]; //Inaltimea fiecarui subarbore

inline int cauta(int i)
{
	while (tati[i] != i) //Radacina arborelui are drept tata pe sine insusi
		i = tati[i]; //Parcurgem spre radacina
	return i;
}
inline void reuneste(int x, int y)
{
	int rx = cauta(x); //Radacina multimii ce il contine pe X
	int ry = cauta(y); //Radacina multimii ce il contine pe Y
	if (inaltime[rx] < inaltime[ry])
		tati[rx] = ry; //Adaugam arborele mai mic, y, la radacina lui x
	else if (inaltime[rx] > inaltime[ry])
		tati[ry] = rx; //Adaugam arborele mai mic, x, la radacina lui y
	else
	{
		tati[rx] = ry; //Adaugam arborele y la radacina arborelui x
		inaltime[ry] += 1; //Inaltimea creste pt ca ambii arbori au aceasi inaltime la care se adauga radacina
	}
}
int main()
{
	ifstream fin("disjoint.in");
	ofstream fout("disjoint.out");
	int operatii; //Nr de operatii
	int multimi; //Nr de multimi
	int operatie, x, y; //Tipul si valorile operatiei
	fin >> multimi >> operatii;
	for (int i = 0; i <= multimi; i++)
	{
		tati[i] = i;
		inaltime[i] = 1;
	}
	while (operatii > 0)
	{
		fin >> operatie >> x >> y;
		if (operatie == 1)
			reuneste(x, y);
		else
			if (cauta(x) == cauta(y))
				fout << "DA\n";
			else
				fout << "NU\n";
		operatii--;
	}
	fin.close();
	fout.close();
	return 0;
}
