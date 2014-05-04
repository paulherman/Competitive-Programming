/*
 * Autor: Paul Herman
 * Problema: Dijkstra cu heap-uri(STL set)
 * Data: 14.10.2011
 * Punctaj: 90
 * Link: http://www.infoarena.ro/problema/dijkstra
 */
#include <fstream>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

struct muchie
{
	int cost; //Costul pentru a ajunge de la A la B
	unsigned short int b; //Nodul B
};

struct nod
{
	bool vizitat;
	int cost;
	vector<muchie> vecini;
};

#define INFINIT 0x3f3f3f

nod noduri[50001]; //Nodurile grafului
unsigned short int n; //Numarul de noduri
unsigned int m; //Nr. de muchii

struct comparare
{
	inline bool operator() (const int& lhs, const int& rhs) const
	{
		return noduri[lhs].cost < noduri[rhs].cost;
	}
};

multiset<short int, comparare> lista; //Heap pt distanta minima fata de sursa

inline void citire()
{
	unsigned short int a;
	muchie b;
	ifstream fin("dijkstra.in");
	fin >> n >> m;
	for (unsigned int i = 1; i <= m ; i++)
	{
		fin >> a >> b.b >> b.cost;
		noduri[a].vecini.push_back(b);
	}
	fin.close();
}
inline void scriere()
{
	ofstream fout("dijkstra.out");
	for (unsigned short int i = 2; i <= n; i++)
		if (noduri[i].vizitat == true)
			fout << noduri[i].cost << " ";
		else
			fout << "0 ";
	fout.close();
}
inline void Dijkstra()
{
	unsigned short int nod_curent = 1;
	noduri[1].cost = 0; //Costul pt. a ajunge la sursa e 0
	lista.insert(1);
	for (unsigned short int i = 2; i <= n; i++)
	{
		noduri[i].vizitat = false; //Nu am vizitat nici und nod
		noduri[i].cost = INFINIT; //Costul pt. a ajunge la restul nodurilor e infinit
	}
	while (lista.empty() == false)
	{
		//Cautam nodul nevizitat cel mai apropiat de sursa
		for (multiset<short int, comparare>::iterator i = lista.begin(); i != lista.end(); i++)
			cout << *i << ' ';
		cout << endl;
		nod_curent = *lista.begin();
		lista.erase(lista.begin());
		noduri[nod_curent].vizitat = true; //Marcam nodul curent ca vizitat
		for (unsigned short int i = 0; i < noduri[nod_curent].vecini.size(); i++) //Parcurgem toti vecinii nodului curent
		{
			if ((noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost) < noduri[noduri[nod_curent].vecini[i].b].cost)
			{
				noduri[noduri[nod_curent].vecini[i].b].cost = noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost;
				lista.insert(noduri[nod_curent].vecini[i].b);
			}
		}		
	}
}
int main()
{
	citire();
	Dijkstra();
	scriere();
	return 0;
}
