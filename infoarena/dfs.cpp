/*
 * Autor: Paul Herman
 * Problema: parcurgere in adancime - componente conexe
 * Data: 01.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/dfs
 */
#include <vector>
#include <fstream>
using namespace std;

struct node
{
	vector<unsigned long int> vertices;
	bool visited;
};

node nodes[100001];
unsigned long int n;
vector<unsigned long int> visit;
unsigned long int to_visit;
unsigned long int k;
unsigned long int conex;
unsigned long int m;

void read()
{
	ifstream fin("dfs.in");
	unsigned long int a, b;
	fin >> n >> m;
	for(unsigned long int i=0; i<=n; i++)
		nodes[i].visited = false;
	for(unsigned long int i=1; i<=m; i++)
	{
		fin >> a >> b;
		nodes[a].vertices.push_back(b);
		nodes[b].vertices.push_back(a);
	}
	fin.close();
}
void dfs()
{
	to_visit = visit.back();
	visit.pop_back();
	for (k = 0; k < nodes[to_visit].vertices.size(); k++)
	{
		if (nodes[nodes[to_visit].vertices[k]].visited == false)
		{
			nodes[nodes[to_visit].vertices[k]].visited = true;
			visit.push_back(nodes[to_visit].vertices[k]);
		}
	}
}
void solve()
{
	conex = 0;
	for(unsigned long int i=1; i<=n; i++)
	{
		if(nodes[i].visited == false)
		{
			conex++;
			visit.push_back(i);
			nodes[i].visited = true;
			while(visit.empty() == false)
				dfs();
		}
	}
}
void print()
{
	ofstream fout("dfs.out");
	fout << conex << "\n";
	fout.close();
}
int main()
{
	read();
	solve();
	print();
	return 0;
}
