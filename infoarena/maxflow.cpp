/*
 * Autor: Paul Herman
 * Problema: Edmonds-Karp
 * Data: 25.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/maxflow
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

#define oo 0x3f3f3f

vector<int> vecini[1001];
int tata[1001], capacitati[1001][1001], flux[1001][1001], noduri, muchii, flux_maxim;
bool vizitat[1001];
deque<int> coada_bfs;

inline bool BFS()
{
    coada_bfs.clear(); //Golim coada in cazul in care dupa o apelare precedenta s-a iesit prin atingerea destinatiei
    int nod_curent = 1; //Pornim de la sursa
    for (int i = 0; i <= noduri; i++)
        vizitat[i] = false; //Marcam toate nodurile ca nevizitate
    vizitat[1] = true; //Am vizitat sursa
    coada_bfs.push_back(1); //Introducem sursa in coada
    while (nod_curent < noduri && coada_bfs.empty() == false)
    {
        nod_curent = coada_bfs.front(); //Luam urmatorul nod din coada
        coada_bfs.pop_front(); //Eliminam elementul curent din coada
        if (nod_curent != noduri)
        {
            //Nu adaugam vecinii pt destinatie
            for (int i = 0; i < vecini[nod_curent].size(); i++)
            {
                //Parcurgem toti vecinii nodului curent
                if ((vizitat[vecini[nod_curent].at(i)] == false) && (flux[nod_curent][vecini[nod_curent].at(i)] != capacitati[nod_curent][vecini[nod_curent].at(i)]))
                {
                    //Daca vecinul nu e vizitat si muchia nu e saturata
                    vizitat[vecini[nod_curent].at(i)] = true; //Marcam vecinul ca vizitat
                    coada_bfs.push_back(vecini[nod_curent].at(i)); //Adaugam vecinul in coada
                    tata[vecini[nod_curent].at(i)] = nod_curent; //Construim arborele de parcurgere
                }
            }
        }
    }
    return vizitat[noduri]; //Statutul destinatiei
}
inline void ek()
{
    int capacitate_reziduala;
    int nod;
    flux_maxim = 0;
    while (BFS() == true) //Cat timp avem drum intre sursa si destinatie
    {
        for (int tata_dest = 0; tata_dest < vecini[noduri].size(); tata_dest++)
        {
            if ((vizitat[vecini[noduri].at(tata_dest)] == true) && (flux[vecini[noduri].at(tata_dest)][noduri] < capacitati[vecini[noduri].at(tata_dest)][noduri]))
            {
                tata[noduri] = vecini[noduri].at(tata_dest);
                capacitate_reziduala = oo;
                for (nod = noduri; nod > 1; nod = tata[nod])
                    capacitate_reziduala = min(capacitate_reziduala, capacitati[tata[nod]][nod] - flux[tata[nod]][nod]);
                if (capacitate_reziduala > 0)
                {
                    for (nod = noduri; nod > 1; nod = tata[nod])
                    {
                        flux[tata[nod]][nod] += capacitate_reziduala;
                        flux[nod][tata[nod]] -= capacitate_reziduala;
                    }
                    flux_maxim += capacitate_reziduala;
                }
            }
        }
    }
}
inline void scriere()
{
    ofstream fout("maxflow.out");
    fout << flux_maxim;
    fout.close();
}
inline void citire()
{
    ifstream fin("maxflow.in");
    int a, b, c;
    fin >> noduri >> muchii;
    for (int i = 0; i < muchii; i++)
    {
        fin >> a >> b >> c;
        capacitati[a][b] += c;
        vecini[a].push_back(b);
        vecini[b].push_back(a);
    }
    fin.close();
}
int main()
{
    citire();
    ek();
    scriere();
    return 0;
}
