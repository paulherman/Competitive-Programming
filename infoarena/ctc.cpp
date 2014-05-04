#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int n, m, lowlink[100001], depth[100001], depth_size;
vector<int> g[100001];
stack<int> s;
bool in_stack[100001];
vector< vector<int> > comp;

inline void citire()
{
	int a, b;
	freopen("ctc.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}
}
inline void scriere()
{
	freopen("ctc.out", "w", stdout);
	printf("%d\n", comp.size());
	for (int i = 0; i < comp.size(); i++)
	{
		for (int j = 0; j < comp[i].size(); j++)
			printf("%d ", comp[i][j]);
		printf("\n");
	}
}
void dfs(int nod)
{
	vector<int> tc;
	int nc;
	depth[nod] = depth_size; //Setam adancimea nodului
	lowlink[nod] = depth_size; //Presupunem ca nodul e radacina
	depth_size++;
	s.push(nod); //Adaugam nodul in stiva
	in_stack[nod] = true; //Marcam nodul ca fiind in stiva
	for (int i = 0; i < g[nod].size(); i++)
	{
		//Parcurem toti vecinii nodului
		if (depth[g[nod][i]] == -1)
		{
			dfs(g[nod][i]); //Vizitam vecinul
			lowlink[nod] = min(lowlink[nod], lowlink[g[nod][i]]); //Cel mai adanc nod la care se poate ajunge
		}
		else if (in_stack[g[nod][i]] == true) //Daca vecinul e fiu
			lowlink[nod] = min(lowlink[nod], lowlink[g[nod][i]]); //Cel mai adanc nod la care se poate ajunge
	}
	if (lowlink[nod] == depth[nod])
	{
		//Daca nodul e radacina scoatem toti fii lui din stiva
		do {
			nc = s.top();
			s.pop();
			in_stack[nc] = false;
			tc.push_back(nc);
		} while (nc != nod);
		comp.push_back(tc);
	}
}
inline void rezolvare()
{
	depth_size = 0;
	for (int i = 1; i <= n; i++)
		depth[i] = -1;
	for (int i = 1; i <= n; i++)
		if (depth[i] == -1)
			dfs(i);
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

