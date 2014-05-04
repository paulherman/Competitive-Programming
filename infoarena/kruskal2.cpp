/*
 * Autor: Paul Herman
 * Problema: APM - Kruskal cu multimi disjuncte
 * Data: 14.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/apm
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct muchie
{
    int a; //Sursa
    int b; //Destinatie
    int cost; //Cost
    bool apartine_apm; //Daca muchia apartine APM
};

int n; //Nr. de varfuri
int m; //Nr. de muchii
muchie muchii[400001]; //Muchiile
int cost_apm; //Costul arborelui
int tati[200001]; //Vector ce contine tatii fiecarui nod
int inaltime[200001]; //Inaltimea fiecarui subarbore

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
inline bool comparare_muchii(muchie a, muchie b)
{
    if (a.cost < b.cost)
        return true;
    else
        return false;
}
inline void citire()
{
    ifstream fin("apm.in");
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> muchii[i].b >> muchii[i].a >> muchii[i].cost;
        muchii[i].apartine_apm = false;
    }
    fin.close();
}
inline void kruskal()
{
    cost_apm = 0;
    for (int i = 0; i <= n; i++)
	{
        tati[i] = i; //Fiecare nod e o componenta conexa
		inaltime[i] = 1;
	}
    sort(&muchii[0], &muchii[m], comparare_muchii); //Sortam muchiile dupa cost
    int c_muchie = 0; //Contorul in vectorul de muchii
    int muchii_adaugate = 0; //Nr. de muchii din APM
    while (muchii_adaugate < (n - 1))
    {
        //APM-ul are n-1 muchii
        if (cauta(muchii[c_muchie].a) != cauta(muchii[c_muchie].b))
        {
            //Daca muchia contine noduri din noduri diferite, aceasta poate fi adaugata
			reuneste(muchii[c_muchie].a, muchii[c_muchie].b);
            cost_apm = cost_apm + muchii[c_muchie].cost; //Modificam costul arborelui
            muchii[c_muchie].apartine_apm = true; //Muchia apartine APM
            muchii_adaugate++; //Incrementam numarul de muchii al APM
        }
        c_muchie++;
    }
}
inline void scriere()
{
    ofstream fout("apm.out");
    fout << cost_apm << "\n" << n-1 << "\n";
    for (int i = 0; i < m; i++)
        if (muchii[i].apartine_apm == true)
            fout << muchii[i].a << " " << muchii[i].b << "\n";
    fout.close();
}
int main()
{
    citire();
    kruskal();
    scriere();
    return 0;
}
