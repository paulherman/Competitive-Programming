/*
 * Autor: Paul Herman
 * Problema: Flux maxim de cost minim - Dijkstra heap
 * Data: 14.01.2012
 * Punctaj: 100
 * Link: http://infoarena.ro/problema/fmcm
 */
#include <fstream>
#include <vector>
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
short int heap_size; //Dimensiunea heapului
short int heap[351]; //Heapul pt dijkstra
short int pozitie[351]; //Pozitiile nodurilor in heap

inline void hswap(int a, int b)
{
	//Interschimbam nodurile
	int t = heap[a];
	heap[a] = heap[b];
	heap[b] = t;
	//Interschimbam pozitiile
	pozitie[heap[a]] = a;
	pozitie[heap[b]] = b;
}

inline void heap_push(int x)
{
	int tata = (x - 1) / 2;
	while ((tata != x) && (distanta[heap[tata]] > distanta[heap[x]]))
	{
		hswap(tata, x);
		x = tata;
		tata = (x - 1) / 2;
	}
}

inline void heap_pop()
{
	heap_size--;
	swap(heap[0], heap[heap_size]);
	pozitie[heap[heap_size]] = -1;
	int modificat = 0;
	int fius, fiud;
	int mic = 0;
	do {
		modificat = mic;
		fius = 2 * modificat + 1;
		fiud = fius + 1;
		mic = modificat;
		if ((fius < heap_size) && (distanta[heap[fius]] < distanta[heap[mic]]))
			mic = fius;
		if ((fiud < heap_size) && (distanta[heap[fiud]] < distanta[heap[mic]]))
			mic = fiud;
		hswap(mic, modificat);
	} while (mic != modificat);
}

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
		pozitie[i] = -1;
	}
	distanta[s] = 0; //Costul pentru a ajunge la sursa este 0
	heap[0] = s; //Introducem sursa in heap
	pozitie[s] = 0; //Sursa este in varful heapului
	heap_size = 1; //Avem doar sursa in heap
	while (heap_size > 0) //Cat timp avem elemente in heap
	{
		nod_curent = heap[0]; //Extragem nodul cel mai apropiat de sursa
		heap_pop(); //Stergem nodul cel mai apropiat de sursa
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
					if (pozitie[vecini[nod_curent][i]] == -1)
					{
						heap[heap_size] = vecini[nod_curent][i];
						pozitie[vecini[nod_curent][i]] = heap_size;
						heap_size++;
					}
					heap_push(pozitie[vecini[nod_curent][i]]);
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

