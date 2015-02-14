#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
	freopen("dijkstra.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);

	const int vertex_max_count = 50001;
	const int infty = 0x3f3f3f;
	int vertex_count, edge_count, distance[vertex_max_count];
	vector< pair<int, int> > adj[vertex_max_count];
	priority_queue< pair<int, int> > q;

	scanf("%d %d", &vertex_count, &edge_count);
	for (int i = 0; i < edge_count; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		adj[u].push_back(make_pair(v, c));
	}

	for (int u = 1; u <= vertex_count; u++)
		distance[u] = infty;
	distance[1] = 0;
	q.push(make_pair(distance[1], 1));

	while (q.empty() == false) {
		pair<int, int> u_pair = q.top();
		int u = u_pair.second;
		int u_cost = u_pair.first;
		q.pop();

		if (u_cost == distance[u]) {
			for (int i = 0; i < (int)adj[u].size(); i++) {
				pair<int, int> v_pair = adj[u][i];
				int v = v_pair.first;
				int weight = v_pair.second;
				if (distance[u] + weight < distance[v]) {
					distance[v] = distance[u] + weight;
					q.push(make_pair(distance[v], v));
				}
			}
		}
	}

	for (int u = 2; u <= vertex_count; u++) {
		if (distance[u] == infty)
			distance[u] = 0;
		printf("%d ", distance[u]);
	}

	return 0;
}
