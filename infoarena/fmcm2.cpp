/*
 * Autor: Paul Herman
 * Problema: Flux maxim de cost minim - Bellman-Ford
 * Data: 13.01.2012
 * Punctaj: 50
 * Link: http://infoarena.ro/problema/fmcm
 */
#include <fstream>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

struct muchie
{
	int cost; //Costul pentru a ajunge de la A la B
	unsigned short int a; //Nodul A
	unsigned short int b; //Nodul B
};

#define INFINIT 0x3f3f3f

int flux_maxim;
int flux[351][351];
int capacitate[351][351];
unsigned int noduri[351]; //Costul pt. a ajunge la fiecare nod
muchie muchii[12501]; //Muchiile grafului
short int drum[351]; //Vector de tati al drumului minim
unsigned short int n; //Numarul de noduri
unsigned short int m; //Nr. de muchii
unsigned short int sursa, destinatie;
bool drum_ameliorare; //Daca mai exista drum de ameliorare;

inline int BF()
{
	bool relaxeaza = true;
	short int a, b;
	int c;
	for (unsigned short int i = 0; i <= n; i++)
		noduri[i] = INFINIT; //Costul pt. a ajunge la restul nodurilor e infinit
	noduri[sursa] = 0; //Costul pt. a ajunge la sursa e 0
	for (unsigned short int i = 1; (i <= n) && (relaxeaza == true); i++)
	{
		//Parcurgem toate nodurile daca am avut vreo relaxare
		relaxeaza = false; //Presupunem ca nu se face nici o relaxare
		for (unsigned int j = 1; j <= m; j++) //Parcurgem toate muchiile
		{
			c = muchii[j].cost;
			a = muchii[j].a;
			b = muchii[j].b;
			if (capacitate[a][b] > flux[a][b])
			{
				if ((noduri[a] + c) < noduri[b])
				{
					//Relaxam muchiile
					noduri[b] = noduri[a] + c;
					drum[b] = a;
					relaxeaza = true;
				}
			}
			if (capacitate[b][a] > flux[b][a])
			{
				if ((noduri[b] - c) < noduri[a])
				{
					//Relaxam muchiile
					noduri[a] = noduri[b] - c;
					drum[a] = b;
					relaxeaza = true;
				}
			}
		}
	}
	short int nod_curent;
	if (noduri[destinatie] < INFINIT)
	{
		drum_ameliorare = true;
		int capacitate_reziduala = INFINIT;
		for (nod_curent = destinatie; nod_curent != sursa; nod_curent = drum[nod_curent])
			if (capacitate_reziduala > (capacitate[drum[nod_curent]][nod_curent] - flux[drum[nod_curent]][nod_curent]))
				capacitate_reziduala = capacitate[drum[nod_curent]][nod_curent] - flux[drum[nod_curent]][nod_curent];
		for (nod_curent = destinatie; nod_curent != sursa; nod_curent = drum[nod_curent])
		{
			flux[nod_curent][drum[nod_curent]] -= capacitate_reziduala;
			flux[drum[nod_curent]][nod_curent] += capacitate_reziduala;
		}
		return noduri[destinatie] * capacitate_reziduala;
	}
	else
	{
		drum_ameliorare = false;
		return 0;
	}
}
inline void fmcm()
{
    flux_maxim = 0;
	do {
		flux_maxim += BF();
	} while (drum_ameliorare == true);
}
inline void citire()
{
    ifstream fin("fmcm.in");
    int f;
    fin >> n >> m >> sursa >> destinatie;
	for (unsigned int i = 1; i <= m ; i++)
	{
		fin >> muchii[i].a >> muchii[i].b >> f >> muchii[i].cost;
        capacitate[muchii[i].a][muchii[i].b] = f;
	}
    fin.close();
}
inline void scriere()
{
    ofstream fout("fmcm.out");
    fout << flux_maxim;
    fout.close();
}
int main()
{
    citire();
    fmcm();
    scriere();
    return 0;
}
