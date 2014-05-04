/*
 * Autor: Paul Herman
 * Data: 16.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/edist
 */
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int lungime_1, lungime_2; //Lungimile string-urilor
string string_1, string_2; //Cele doua string-uri
int distanta_maxima; //Distanta maxima dintre string-uri
int dinamica[2][20001]; //Matricea pt dinamica(doar doua linii interschimbate)
int lungime_min, lungime_max; //Lungimea minima, maxima a string-urilor
int linie_curenta, linie_precedenta, linie_temp; //Linia curenta, precedenta, temporara in matrice
int j_inceput, j_sfarsit; //Valorile de inceput si sfarsit pt parcurgerea dinamicii pe orizontala

int distanta_levenshend()
{
	linie_precedenta = 0;
	linie_curenta = 1;
	for (int i = 0; i <= lungime_max; i++)
		dinamica[linie_precedenta][i] = i;
	for (int i = 1; i <= lungime_max; i++)
	{
		dinamica[linie_curenta][0] = i;
		if (1 > (i - distanta_maxima))
			j_inceput = 1;
		else
			j_inceput = i - distanta_maxima;
		if (lungime_min < i + distanta_maxima)
			j_sfarsit = lungime_min;
		else
			j_sfarsit = i + distanta_maxima;
		for (int j = j_inceput; j <= j_sfarsit; j++)
		{
			if (string_1.at(j-1) == string_2.at(i-1))
				dinamica[linie_curenta][j] = dinamica[linie_precedenta][j-1];
			else
				dinamica[linie_curenta][j] = 1 + min(dinamica[linie_precedenta][j-1], min(dinamica[linie_precedenta][j], dinamica[linie_curenta][j-1]));
		}
		linie_temp = linie_curenta;
		linie_curenta = linie_precedenta;
		linie_precedenta = linie_temp;
	}
	return dinamica[linie_precedenta][lungime_min];
}
int main()
{
	ifstream fin("edist.in");
	ofstream fout("edist.out");
	fin >> lungime_1 >> lungime_2 >> distanta_maxima;
	if (lungime_1 > lungime_2)
	{
		lungime_max = lungime_1;
		lungime_min = lungime_2;
		fin >> string_2 >> string_1;
	}
	else
	{
		lungime_max = lungime_2;
		lungime_min = lungime_1;
		fin >> string_1 >> string_2;
	}
	fout << distanta_levenshend();
	fout.close();
	fin.close();
	return 0;
}
