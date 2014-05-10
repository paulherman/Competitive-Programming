#include <cstdio>
#include <vector>
using namespace std;

int n, *dp, *depth, current_depth, *visited, **bridges, bridge_count;
vector<int> *adj;

void dfs(int u, int parent) {
	current_depth++;
	depth[u] = current_depth;
	dp[u] = current_depth;
	visited[u] = 1;

	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (visited[v] == 0) {
			dfs(v, u);
			dp[u] = min(dp[u], dp[v]); // can get higher in DFS tree from one of the subtrees

			if (dp[v] > depth[u]) {
				bridge_count++;
				bridges[u][v] = 1;
				bridges[v][u] = 1;
			}

		} else if (v != parent)
			dp[u] = min(dp[u], depth[v]); // v is higher in DFS tree (i.e. back-edge)
	}
}
int main() {
	while (scanf("%d", &n) == 1) {
		adj = new vector<int>[n];
		dp = new int[n];
		visited = new int[n];
		depth = new int[n];
		bridges = new int*[n];
		for (int i = 0; i < n; i++) {
			bridges[i] = new int[n];
			for (int j = 0; j < n; j++)
				bridges[i][j] = 0;
		}

		for (int i = 0; i < n; i++) {
			int u, adj_size, v;
			scanf("%d (%d)", &u, &adj_size);
			visited[u] = 0;
			for (int j = 0; j < adj_size; j++) {\
				scanf("%d", &v);
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		bridge_count = 0;
		current_depth = 0;

		for (int u = 0; u < n; u++)
			if (visited[u] == 0)
				dfs(u, -1);

		printf("%d critical links\n", bridge_count);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (bridges[i][j] == 1)
					printf("%d - %d\n", i, j);
		printf("\n");

		delete[] adj;
		delete[] dp;
		delete[] visited;
		delete[] depth;
		for (int i = 0; i < n; i++)
			delete[] bridges[i];
		delete[] bridges;
	}
	return 0;
}