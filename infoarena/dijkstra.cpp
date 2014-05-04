/*
 * Autor: Paul Herman
 * Problema: Dijkstra(n^2)
 * Data: 01.10.2011
 * Punctaj: 50
 * Link: http://www.infoarena.ro/problema/dijkstra
 */
#include <fstream>
#include <vector>
using namespace std;

struct muchie
{
	int cost; //Costul pentru a ajunge de la A la B
	unsigned int b; //Nodul B
};

struct nod
{
	bool vizitat;
	int cost;
	vector<muchie> vecini;
};

#define INFINIT 0x3f3f3f

nod noduri[250001]; //Nodurile grafului
unsigned short int n; //Numarul de noduri
unsigned int m; //Nr. de muchii

void citire()
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
void scriere()
{
	ofstream fout("dijkstra.out");
	for (unsigned short int i = 2; i <= n; i++)
	{
		if (noduri[i].vizitat == true)
			fout << noduri[i].cost << " ";
		else
			fout << "0 ";
	}
	fout.close();
}
void Dijkstra()
{
	unsigned short int nod_curent = 1;
	unsigned int min_dist;
	noduri[1].cost = 0; //Costul pt. a ajunge la sursa e 0
	for (unsigned short int i = 2; i <= n; i++)
	{
		noduri[i].vizitat = false; //Nu am vizitat nici und nod
		noduri[i].cost = INFINIT; //Costul pt. a ajunge la restul nodurilor e infinit
	}
	while (nod_curent > 0)
	{
		noduri[nod_curent].vizitat = true; //Marcam nodul curent ca vizitat
		for (unsigned short int i = 0; i < noduri[nod_curent].vecini.size(); i++) //Parcurgem toti vecinii nodului curent
			if ((noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost) < noduri[noduri[nod_curent].vecini[i].b].cost)
				noduri[noduri[nod_curent].vecini[i].b].cost = noduri[nod_curent].cost + noduri[nod_curent].vecini[i].cost;
		//Cautam nodul nevizitat cel mai apropiat de sursa
		nod_curent = 0;
		min_dist = INFINIT;
		for (unsigned short int i = 2; i <= n; i++)
		{
			if ((noduri[i].vizitat == false) && (noduri[i].cost < min_dist))
			{
				nod_curent = i;
				min_dist = noduri[i].cost;
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

