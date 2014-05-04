/*
 * Autor: Paul Herman
 * Problema: Flux maxim de cost minim - Dijkstra coada
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
	short int cost; //Costul pentru a parcurge muchia
	unsigned short int b; //Nodul B
};

struct nod
{
	bool vizitat;
	int cost;
	vector<muchie> vecini;
};

#define INFINIT 0x3f3f3f

int flux_maxim;
int flux[351][351];
int capacitate[351][351];
nod noduri[351]; //Nodurile grafului
short int drum[351]; //Vector de tati al drumului minim
unsigned short int n; //Numarul de noduri
unsigned short int m; //Nr. de muchii
unsigned short int sursa, destinatie;
bool drum_ameliorare; //Daca mai exista drum de ameliorare;

struct comparare
{
	inline bool operator() (const short int& lhs, const short int& rhs) const
	{
		return noduri[lhs].cost < noduri[rhs].cost;
	}
};
multiset<short int, comparare> lista; //Heap pt distanta minima fata de sursa

inline int Dijkstra()
{
	for (unsigned short int i = 1; i <= n; i++)
	{
		noduri[i].vizitat = false; //Nu am vizitat nici und nod
		noduri[i].cost = INFINIT; //Costul pt. a ajunge la restul nodurilor e infinit
	}
	short int nod_curent = sursa;
	noduri[sursa].cost = 0; //Costul pt. a ajunge la sursa e 0
	lista.insert(sursa);
	while (lista.empty() == false)
	{
		//Cautam nodul nevizitat cel mai apropiat de sursa
		nod_curent = *lista.begin();
		lista.erase(lista.begin());
		noduri[nod_curent].vizitat = false; //Marcam nodul curent ca nevizitat(in cazul revenirii pe un alt drum)
		for (unsigned short int i = 0; i < noduri[nod_curent].vecini.size(); i++) //Parcurgem toti vecinii nodului curent
		{
			if (capacitate[nod_curent][noduri[nod_curent].vecini[i].b] > flux[nod_curent][noduri[nod_curent].vecini[i].b])
			{
				if ((noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost) < noduri[noduri[nod_curent].vecini[i].b].cost)
				{
					noduri[noduri[nod_curent].vecini[i].b].cost = noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost;
					drum[noduri[nod_curent].vecini[i].b] = nod_curent; //In acest vecin ajungem din nodul curent
					if (noduri[noduri[nod_curent].vecini.at(i).b].vizitat == false)
					{
						noduri[noduri[nod_curent].vecini.at(i).b].vizitat = true;
						lista.insert(noduri[nod_curent].vecini[i].b); //Adaugam vecinul in coada
					}
				}
			}
		}
	}
	if (noduri[destinatie].cost < INFINIT)
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
		return noduri[destinatie].cost * capacitate_reziduala;
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
		flux_maxim += Dijkstra();
	} while (drum_ameliorare == true);
}
inline void citire()
{
    ifstream fin("fmcm.in");
    int a, b, f, c;
    muchie l;
    fin >> n >> m >> sursa >> destinatie;
	for (unsigned int i = 1; i <= m ; i++)
	{
		fin >> a >> b >> f >> c;
        l.cost = c;
        l.b = b;
        noduri[a].vecini.push_back(l);
        l.b = a;
        l.cost = -c;
        noduri[b].vecini.push_back(l); //Muchia inversa
        capacitate[a][b] = f;
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

