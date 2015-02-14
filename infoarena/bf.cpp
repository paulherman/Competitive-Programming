#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
using namespace std;


const int infty = 0x3f3f3f;
int dist[50005], n, m;
bool in_queue[50005];
queue<int> q;
vector< pair<int, int> > adj[50005];

int main() {
	freopen("dijkstra.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		adj[u].push_back(make_pair(v, cost));
		adj[v].push_back(make_pair(u, cost));
	}

	for (int i = 1; i <= n; i++)
		dist[i] = oo;

	dist[1] = 0;
	q.push(1);
	in_queue[1] = true;

	while (q.empty() == false) {
		int u = q.front();
		q.pop();
		in_queue[u] = false;

		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i].first;
			int weight = adj[u][i].second;

			if (dist[u] + weight < dist[v]) {
				dist[v] = dist[u] + weight;
				if (in_queue[v] == false) {
					q.push(v);
					in_queue[v] = true;
				}
			}
		}
	}


	for (int i = 2; i <= n; i++) {
		if (dist[i] == infty)
			dist[i] = 0;
		printf("%d ", dist[i]);
	}

	return 0;
}
