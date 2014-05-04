/*
 * Autor: Paul Herman
 * Problema: APM - Prim
 * Data: 01.10.2011
 * Punctaj: 60
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
int componente[200001]; //Componentele conexe

inline bool comparare_muchii(muchie a, muchie b)
{
	return (a.cost < b.cost);
}
inline void citire()
{
	ifstream fin("apm.in");
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		fin >> muchii[i].b >> muchii[i].a >> muchii[i].cost;
	}
	fin.close();
}
inline void prim()
{
	cost_apm = 0;
	for (int i = 1; i <= n; i++)
		componente[i] = i; //Fiecare nod e o componenta conexa
	sort(muchii, muchii + m, comparare_muchii); //Sortam muchiile dupa cost
	int muchii_adaugate = 0; //Nr. de muchii din APM
	int componenta = muchii[0].a; //Initial adaugam muchia cu costul minim deci componenta va fi unul din varfurile muchiei
	bool adaugat; //La fiecare pas cautam o muchie de cost minim pt care unul si numai unul din varfuri apartine componentei conexe
	int a;
	while (muchii_adaugate < (n - 1)) //APM-ul are n-1 muchii
	{
		adaugat = false; //Presupunem ca nu am adaugat o muchie
		for (; ((a < m) && (adaugat == false)); a++)
		{
			if ((componente[muchii[i].b] == componenta || componente[muchii[i].a] == componenta) && (componente[muchii[i].b] != componente[muchii[i].a]))
			{
				//Daca unul si numai unul din varfuri apartine componentei conexe, adaugam muchia
				muchii[i].apartine_apm = true;
				componente[muchii[i].a] = componenta;
				componente[muchii[i].b] = componenta;
				cost_apm = cost_apm + muchii[i].cost;
				adaugat = true;
				muchii_adaugate++;
			}
		}
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
	prim();
	scriere();
	return 0;
}

