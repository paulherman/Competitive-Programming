/*
 * Autor: Paul Herman
 * Problema: sortare topologica
 * Data: 13.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/sortaret
 */
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

bool vizitat[50001]; //Lista de vecini a fiecarui nod
vector<int> vecini[50001]; //Starea de vizitare a fiecarui nod
deque<int> coada;
int n, m;

inline void dfs(int nod)
{
	vizitat[nod] = true;
	for (int i = 0; i < vecini[nod].size(); i++)
		if (vizitat[vecini[nod][i]] == false)
			dfs(vecini[nod][i]);
	coada.push_front(nod);
}
inline void sortare_topologica()
{
	for (int i = 1; i <= n; i++)
		if (vizitat[i] == false)
			dfs(i);
}
inline void scriere()
{
	ofstream fout("sortaret.out");
	for (int i = 0; i < coada.size(); i++)
		fout << coada[i] << ' ';
	fout.close();
}
inline void citire()
{
	int a, b; //Nodurile intre care vom avea muchie
	ifstream fin("sortaret.in");
	fin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		fin >> a >> b;
		vecini[a].push_back(b);
	}
	fin.close();
}
int main()
{
	citire();
	sortare_topologica();
	scriere();
	return 0;
}

