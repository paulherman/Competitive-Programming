/*
 * Autor: Paul Herman
 * Problema: Bellman-Ford(n*m)
 * Data: 01.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/dijkstra
 */
#include <fstream>
using namespace std;

struct muchie
{
	int cost; //Costul pentru a ajunge de la A la B
	unsigned short int a; //Nodul A
	unsigned short int b; //Nodul B
};

#define INFINIT 0x3f3f3f

unsigned int noduri[50001]; //Costul pt. a ajunge la fiecare nod
muchie muchii[250001]; //Muchiile grafului
unsigned short int n; //Numarul de noduri
unsigned int m; //Nr. de muchii

void citire()
{
	ifstream fin("dijkstra.in");
	fin >> n >> m;
	for (unsigned int i = 1; i <= m ; i++)
		fin >> muchii[i].a >> muchii[i].b >> muchii[i].cost;
	fin.close();
}
void scriere()
{
	ofstream fout("dijkstra.out");
	for (unsigned short int i = 2; i <= n; i++)
	{
		if (noduri[i] < INFINIT)
			fout << noduri[i] << " ";
		else
			fout << "0 ";
	}
	fout.close();
}
void BF()
{
	bool relaxeaza = true;
	noduri[1] = 0; //Costul pt. a ajunge la sursa e 0
	for (unsigned short int i = 2; i <= n; i++)
		noduri[i] = INFINIT; //Costul pt. a ajunge la restul nodurilor e infinit
	for (unsigned short int i = 1; (i <= n) && (relaxeaza == true); i++)
	{
		//Parcurgem toate nodurile daca am avut vreo relaxare
		relaxeaza = false; //Presupunem ca nu se face nici o relaxare
		for (unsigned int j = 1; j <= m; j++) //Parcurgem toate muchiile
		{
			if ((noduri[muchii[j].a] + muchii[j].cost) < noduri[muchii[j].b])
			{
				//Relaxam muchiile
				noduri[muchii[j].b] = noduri[muchii[j].a] + muchii[j].cost;
				relaxeaza = true;
			}
		}
	}
}
int main()
{
	citire();
	BF();
	scriere();
	return 0;
}
