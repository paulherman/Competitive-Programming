#include <cstdio>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

// dp[u] = heighest node in dfs tree we can get from u or its subtrees
int n, dp[105], depth[105], current_depth, visited[105], articulation_points;
vector<int> adj[105];

void dfs(int u, int parent) {
	int subtrees = 0;
	bool is_articulation_point = false;
	current_depth++;
	depth[u] = current_depth;
	dp[u] = current_depth;
	visited[u] = 1;

	for (int i = 0; i < (int)adj[u].size(); i++) {
		subtrees++;
		int v = adj[u][i];
		if (visited[v] == 0) {
			dfs(v, u);
			dp[u] = min(dp[u], dp[v]); // can get higher in DFS tree from one of the subtrees

			if (parent == 0 && subtrees > 1)
				is_articulation_point = true;

			if (parent != 0 && dp[v] >= depth[u])
				is_articulation_point = true;

		} else if (v != parent)
			dp[u] = min(dp[u], depth[v]); // v is higher in DFS tree (i.e. back-edge)
	}
	if (is_articulation_point)
		articulation_points++;
}

int main() {
	char line[255];
	while (gets(line)) {
		sscanf(line, "%d", &n);
		memset(line, 0, sizeof(line));
		if (n == 0)
			break;

		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			visited[i] = 0;
		}

		while (gets(line) && line[0] != '0') {
			istringstream str(line);
			int u, v;
			str >> u;
			while (str >> v) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			memset(line, 0, sizeof(line));
		}

		articulation_points = 0;
		current_depth = 0;
		dfs(1, 0);

		printf("%d\n", articulation_points);
	}

	return 0;
}