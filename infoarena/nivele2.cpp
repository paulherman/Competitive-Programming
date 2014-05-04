/*
 * Autor: Paul Herman
 * Data: 15.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/nivele2
 */
#include <fstream>
#include <vector>
using namespace std;

struct nod
{
	bool vizitat; //Am vizitat nodul
	vector<int> vecini; //Vecinii fiecarui nod
};

nod arbore[100001]; //Lista de vecini ai fiecarui nod
int noduri; //Nr de noduri
vector<int>vizitare; //Coada de vizitare pt BFS

inline void citire()
{
	ifstream fin("nivele2.in");
	fin >> noduri;
	int a, b;
	for (int i = 0; i < (noduri - 1); i++)
	{
		fin >> a >> b;
		arbore[a].vecini.push_back(b);
		arbore[b].vecini.push_back(a);
	}
	fin.close();
}
inline void bfs()
{
	ofstream fout("nivele2.out");
	vizitare.push_back(1); //Adaugam radacina in coada
	unsigned int sfarsit_nivel = vizitare.size(); //Primul nivel se termina dupa radacina
	int nivel = 1; //Pornim de la primul nivel
	unsigned int i = 0; //Contorul in coada
	fout << "nivelul 1:";
	while (i < vizitare.size()) //Cat timp nu am ajuns la sfarsitul cozii
	{
		if (i == sfarsit_nivel) //Daca s-a terminat nivelul curent
		{
			nivel++; //Trecem la urmatorul nivel
			fout << '\n' << "nivelul " << nivel << ":";
			sfarsit_nivel = vizitare.size(); //Sfarsitul urmatorului nivel este la sfarsitul cozii
		}
		fout << " " << vizitare.at(i);
		arbore[vizitare.at(i)].vizitat = true; //Marcam nodul ca vizitat
		for (unsigned int v = 0; v < arbore[vizitare.at(i)].vecini.size(); v++)
			if(arbore[arbore[vizitare.at(i)].vecini.at(v)].vizitat == false)
				vizitare.push_back(arbore[vizitare.at(i)].vecini.at(v)); //Adaugam toti vecinii in coada
		i++; //Incrementam contorul in coada
	}
	fout.close();
}
int main()
{
	citire();
	bfs();
	return 0;
}
