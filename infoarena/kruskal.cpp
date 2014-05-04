/*
 * Autor: Paul Herman
 * Problema: APM - Kruskal cu componente liniare
 * Data: 01.10.2011
 * Punctaj: 70
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
int noduri[200001]; //nodurile conexe

inline bool comparare_muchii(muchie a, muchie b)
{
    if (a.cost < b.cost)
        return true;
    else
        return false;
}
inline void citire()
{
    ifstream fin("apm.in");
    fin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> muchii[i].b >> muchii[i].a >> muchii[i].cost;
        muchii[i].apartine_apm = false;
    }
    fin.close();
}
inline void kruskal()
{
    cost_apm = 0;
    for (int i = 1; i <= n; i++)
        noduri[i] = i; //Fiecare nod e o componenta conexa
    sort(&muchii[0], &muchii[m], comparare_muchii); //Sortam muchiile dupa cost
    int c_muchie = 0; //Contorul in vectorul de muchii
    int muchii_adaugate = 0; //Nr. de muchii din APM
    int c_modificata; //Valoarea nodurii celui de-al doilea nod al muchiei
    while (muchii_adaugate < (n - 1))
    {
        //APM-ul are n-1 muchii
        if (noduri[muchii[c_muchie].a] != noduri[muchii[c_muchie].b])
        {
            //Daca muchia contine noduri din noduri diferite, aceasta poate fi adaugata
            c_modificata = noduri[muchii[c_muchie].b];
            for (int i = 1; i <= n; i++)
                if (noduri[i] == c_modificata)
                    noduri[i] = noduri[muchii[c_muchie].a]; //Toate elementele componentei b se adauga la a
            cost_apm = cost_apm + muchii[c_muchie].cost; //Modificam costul arborelui
            muchii[c_muchie].apartine_apm = true; //Muchia apartine APM
            muchii_adaugate++; //Incrementam numarul de muchii al APM
        }
        c_muchie++;
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
    kruskal();
    scriere();
    return 0;
}
