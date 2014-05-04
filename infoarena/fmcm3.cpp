/*
 * Autor: Paul Herman
 * Problema: Flux maxim de cost minim - Dijkstra STL
 * Data: 13.01.2012
 * Punctaj: 50
 * Link: http://infoarena.ro/problema/fmcm
 */
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define oo 0x3f3f3f

short int n; //Nr. de noduri
short int m; //Nr. de muchii
short int s; //Sursa
short int d; //Destinatia
vector<short int> vecini[351]; //Lista de vecini
short int cost[351][351]; //Matricea costurilor
short int capacitate[351][351]; //Matricea capacitatilor
short int flux[351][351]; //Matricea fluxurilor
long long int cost_minim; //Costul minim pentru a baga cantitatea maxima de flux
int distanta[351]; //Costul pentru a ajunge la fiecare nod
short int drum[351]; //Tatal de la care se ajunge in fiecare nod (asemenea arborelui BFS)
bool drum_ameliorare; //Daca exista drum care sa imbunatateasca fluxul
short int nod_curent = 0; //Nodul scos din heap
int capacitate_reziduala; //Capacitatea cu care se mareste fluxul pe un drum
int cost_destinatie; //Costul pt a ajunge la destinatie, modificat datorita transformarii pt Dijkstra

struct comparare
{
	inline bool operator() (const int& lhs, const int& rhs) const
	{
		return distanta[lhs] < distanta[rhs];
	}
};

priority_queue<int, vector<int>, comparare> heap; //Heap-ul folosit pt Dijkstra

inline void Bellman_Ford()
{
	bool relaxare = true;
	for (int i = 1; i <= n; i++)
		distanta[i] = oo; //Presupunem costul pentru a ajunge la toate nodurile este infinit
	distanta[s] = 0; //Costul pentru a ajunge la sursa este 0
	for (int i = 1; (i <= n) && (relaxare == true); i++)
	{
		//Parcurgem toate nodurile daca am avut vreo
		relaxare = false;
		for (int j = 1; j <= n; j++) //Parcurgem toate nodurile
		{
			for (int k = 0; k < vecini[j].size(); k++) //Parcurgem toti vecinii
			{
				if (capacitate[j][vecini[j][k]] > flux[j][vecini[j][k]]) //Daca muchia nu e saturata
				{
					if (distanta[vecini[j][k]] > (distanta[j] + cost[j][vecini[j][k]])) //Daca muchia micsoreaza distanta
					{
						relaxare = true;
						distanta[vecini[j][k]] = distanta[j] + cost[j][vecini[j][k]];
					}
				}
			}
		}
	}
	cost_destinatie = distanta[d];
}

inline int Dijkstra()
{
	//Transformam costurile astfel incat sa fie pozitive
	for (short int i = 1; i <= n; i++)
		for (short int j = 0; j < vecini[i].size(); j++)
			if ((distanta[i] < oo) && (distanta[vecini[i][j]] < oo))
				cost[i][vecini[i][j]] += distanta[i] - distanta[vecini[i][j]];
	for (short int i = 0; i <= n; i++)
	{
		distanta[i] = oo; //Presupunem costul pentru a ajunge la toate nodurile este infinit
		drum[i] = 0; //Presupunem ca nodul este inaccesibil
	}
	distanta[s] = 0; //Costul pentru a ajunge la sursa este 0
	heap.push(s); //Introducem sursa in heap
	while (heap.empty() == false) //Cat timp avem elemente in heap
	{
		nod_curent = heap.top();
		heap.pop();
		for (int i = 0; i < vecini[nod_curent].size(); i++)
		{
			if (capacitate[nod_curent][vecini[nod_curent][i]] > flux[nod_curent][vecini[nod_curent][i]])
			{
				//Daca muchia nu e saturata
				if (distanta[vecini[nod_curent][i]] > (distanta[nod_curent] + cost[nod_curent][vecini[nod_curent][i]]))
				{
					//Daca muchia imbunatateste costul
					distanta[vecini[nod_curent][i]] = distanta[nod_curent] + cost[nod_curent][vecini[nod_curent][i]];
					drum[vecini[nod_curent][i]] = nod_curent;
					heap.push(vecini[nod_curent][i]);
				}
			}
		}
	}
	if (distanta[d] < oo)
	{
		//Daca exista drum de ameliorare
		drum_ameliorare = true;
		//Calculam capacitatea de flux care poate fi bagata
		capacitate_reziduala = oo;
		for (nod_curent = d; nod_curent != s; nod_curent = drum[nod_curent])
			capacitate_reziduala = min(capacitate_reziduala, capacitate[drum[nod_curent]][nod_curent] - flux[drum[nod_curent]][nod_curent]);
		//Bagam fluxul si ne asiguram de anti-simetrie
		for (nod_curent = d; nod_curent != s; nod_curent = drum[nod_curent])
		{
			flux[drum[nod_curent]][nod_curent] += capacitate_reziduala;
			flux[nod_curent][drum[nod_curent]] -= capacitate_reziduala;
		}
		cost_destinatie += distanta[d]; //Modificam costul destinatiei datorita transformarii
		return cost_destinatie * capacitate_reziduala;
	}
	else
	{
		drum_ameliorare = false;
		return 0;
	}
}

inline void fmcm()
{
	Bellman_Ford();
	do {
		cost_minim += Dijkstra();
	} while(drum_ameliorare == true);
}

inline void citire()
{
	short int a, b, ccapacitate, ccost;
	ifstream fin("fmcm.in");
	fin >> n >> m >> s >> d;
	for (int i = 1; i <= m; i++)
	{
		fin >> a >> b >> ccapacitate >> ccost;
		vecini[a].push_back(b);
		vecini[b].push_back(a);
		cost[a][b] = ccost;
		cost[b][a] = -ccost;
		capacitate[a][b] = ccapacitate;
		capacitate[b][a] = 0;
	}
	fin.close();
}

inline void scriere()
{
	ofstream fout("fmcm.out");
	fout << cost_minim;
	fout.close();
}

int main()
{
	citire();
	fmcm();
	scriere();
	return 0;
}

