/*
 * Autor: Paul Herman
 * Problema: Dijkstra cu heap-uri
 * Data: 14.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/dijkstra
 */
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

struct muchie
{
	int cost; //Costul pentru a ajunge de la A la B
	int b; //Nodul B
};

#define oo 0x3f3f3f

vector<muchie> vecini[50001]; //Nodurile grafului
int distanta[50001]; //Distantele pana la noduri
int n; //Numarul de noduri
int m; //Nr. de muchii
int pozitie[50001]; //Pozitiile nodurilor in heap
int heap[50001]; //Heapul ce pastreaza distanta nodurilor fata de sursa
int heap_size; //Dimensiunea heapului

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
	pozitie[heap[heap_size]] = 0;
	pozitie[heap[0]] = -1;
	heap[0] = heap[heap_size];
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
inline void citire()
{
	int a;
	muchie b;
	ifstream fin("dijkstra.in");
	fin >> n >> m;
	for (int i = 1; i <= m ; i++)
	{
		fin >> a >> b.b >> b.cost;
		vecini[a].push_back(b);
	}
	fin.close();
}
inline void scriere()
{
	ofstream fout("dijkstra.out");
	for (int i = 2; i <= n; i++)
		if (distanta[i] < oo)
			fout << distanta[i] << " ";
		else
			fout << "0 ";
	fout.close();
}
inline void Dijkstra()
{
	int nod_curent = 1;
	distanta[1] = 0; //Costul pt. a ajunge la sursa e 0
	heap_size = 1; //Heapul contine doar sursa
	heap[0] = 1; //Cel mai mic element este sursa
	pozitie[1] = 0; //Pozitia sursei este in varful heapului
	for (int i = 2; i <= n; i++)
	{
		distanta[i] = oo; //Costul pt. a ajunge la restul nodurilor e infinit
		pozitie[i] = -1; //Nodurile nu sunt in heap
	}
	while (heap_size > 0)
	{
		nod_curent = heap[0]; //Extragem nodul cel mai apropiat de sursa
		heap_pop(); //Stergem nodul cel mai apropiat de sursa
		for (int i = 0; i < vecini[nod_curent].size(); i++) //Parcurgem toti vecinii nodului curent
		{
			if ((distanta[nod_curent] + vecini[nod_curent][i].cost) < distanta[vecini[nod_curent][i].b])
			{
				distanta[vecini[nod_curent][i].b] = distanta[nod_curent] + vecini[nod_curent][i].cost;
				if (pozitie[vecini[nod_curent][i].b] == -1) //Adaugam nodul in heap
				{
					heap[heap_size] = vecini[nod_curent][i].b;
					pozitie[vecini[nod_curent][i].b] = heap_size;
					heap_size++;					
				}
				heap_push(pozitie[vecini[nod_curent][i].b]); //Urcam nodul cu distanta imbunatatita in heap
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
