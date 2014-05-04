#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int current;
int type, a, b;

void add(int father, int child)
{
}
int query(int node, int height)
{
}
void init()
{
	current = 0;
}
int main()
{
	ifstream fin("citylog.in");
	ofstream fout("citylog.out");
	fin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		fin >> type >> a >> b;
		if (type == 0)
			add(b ^ current, a ^ current);
		else
			fout << query(a ^ current, b ^ current) << '\n';
	}
	fin.close();
	fout.close();
	return 0;
}
