#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
	freopen("bfs.in", "r", stdin);
	freopen("bfs.out", "w", stdout);

	const int MAX_V = 100005;
	int E, V, s, d[MAX_V];
	bool visited[MAX_V] = { false };
	vector<int> adj[MAX_V];
	queue<int> q;

	scanf("%d %d %d", &V, &E, &s);
	for (int i = 0; i < E; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}

	for (int v = 1; v <= V; v++)
		d[v] = -1;

	q.push(s);
	d[s] = 0;
	visited[s] = true;

	while(q.empty() == false) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i];
			if (visited[v] == false) {
				visited[v] = true;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	for (int v = 1; v <= V; v++)
		printf("%d ", d[v]);

	return 0;
}

