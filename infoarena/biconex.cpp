#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, dist[100001], sus[100001];
vector<int> g[100001];
stack< pair<int, int> > stiva;
vector< vector<int> > comp;
bool vizitat[100001];

inline void citire()
{
	int a, b;
	freopen("biconex.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
inline void scriere()
{
	freopen("biconex.out", "w", stdout);
	printf("%d\n", comp.size());
	for (int i = 0; i < comp.size(); i++)
	{
		for (int j = 0; j < comp[i].size(); j++)
			printf("%d ", comp[i][j]);
		printf("\n");
	}
}
void componenta(int a, int b)
{
	int x, y;
	vector<int> tc;
	do {
		x = stiva.top().first;
		y = stiva.top().second;
		stiva.pop();
		tc.push_back(x);
		tc.push_back(y);
	} while ((x != a) || (y != b));
	sort(tc.begin(), tc.end());
	vector<int>::iterator new_size = unique(tc.begin(), tc.end());
	tc.resize(new_size - tc.begin());
	comp.push_back(tc);
}
void dfs(int nod)
{
	vizitat[nod] = true;
	sus[nod] = dist[nod];
	for (int i = 0; i < g[nod].size(); i++)
	{
		if (vizitat[g[nod][i]] == false)
		{
			dist[g[nod][i]] = dist[nod] + 1;
			stiva.push(make_pair(nod, g[nod][i])); //Adaugam muchia in stiva
			dfs(g[nod][i]);
			if (sus[g[nod][i]] >= dist[nod])
				componenta(nod, g[nod][i]);
			sus[nod] = min(sus[nod], sus[g[nod][i]]);
		}
		else
			sus[nod] = min(sus[nod], dist[g[nod][i]]);
	}
}
int main()
{
	citire();
	dfs(1);
	scriere();
	return 0;
}

