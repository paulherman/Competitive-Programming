#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#define byte unsigned char

byte n, cost[101];
vector<byte> g[101];
bool vizitat[101];
int cost_total;
queue<byte> q;

inline void citire()
{
	int nd, d, c;
	ifstream fin("pm2.in");
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		fin >> c;
		cost[i] = c;
	}
	for (int i = 1; i <= n; i++)
	{
		fin >> nd;
		for (int j = 1; j <= nd; j++)
		{
			fin >> d;
			g[i].push_back(d);
		}
	}
	fin.close();
}
inline void scriere()
{
	ofstream fout("pm2.out");
	fout << cost_total << '\n';
	fout.close();
}
void dfs(byte x)
{
	vizitat[x] = true;
	for (int i = 0; i < g[x].size(); i++)
		if (vizitat[g[x][i]] == false)
			dfs(g[x][i]);
	q.push(x);
}
inline int dfs_cost(byte x)
{
	if (vizitat[x] == false)
	{
		vizitat[x] = true;
		for (int i = 0; i < g[x].size(); i++)
			cost_total = max(m, bfs(g[x][i])) + cost[x];
	}
	else
		return 0;
}
inline void rezolvare()
{
	for (int i = 1; i <= n; i++)
		if (vizitat[i] == false)
			dfs[i];
	for (int i = 1; i <= n; i++)
		vizitat[i] = false;
	for (int i = 0; i < q.size(); i++)
		if (vizitat[i] == false)
			dfs_cost(q[i]);
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

