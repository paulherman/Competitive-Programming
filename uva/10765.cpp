#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// dp[u] = heighest node in dfs tree we can get from u or its subtrees
int n, m, dp[10005], depth[10005], current_depth, visited[10005];
vector<int> adj[10005];
vector< pair<int, int> > articulation_points;

void dfs(int u, int parent) {
	int children = 0;
	int subtrees = 0;
	bool is_articulation_point = false;
	current_depth++;
	depth[u] = current_depth;
	dp[u] = current_depth;
	visited[u] = 1;

	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		children++;
		if (visited[v] == 0) {
			subtrees++; // number of connected components if removing u
			dfs(v, u);
			dp[u] = min(dp[u], dp[v]); // can get higher in DFS tree from one of the subtrees

			if (dp[v] >= depth[u])
				is_articulation_point = true;

		} else if (v != parent)
			dp[u] = min(dp[u], depth[v]); // v is higher in DFS tree (i.e. back-edge)
	}

	if (parent == -1 && children < 2)
		is_articulation_point = false;

	if (is_articulation_point && parent != -1)
		subtrees++; // the parent is considered a subtree
	else if (!is_articulation_point)
		subtrees = 1; // only one subtree

	articulation_points.push_back(make_pair(subtrees, -u));
}

int main() {
	while (scanf("%d %d", &n, &m), n != 0 && m != 0) {
		int u, v;

		for (int i = 0; i < n; i++) {
			adj[i].clear();
			visited[i] = 0;
		}
		articulation_points.clear();
		current_depth = 0;

		while (scanf("%d %d", &u, &v), u != -1 && v != -1) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0, -1);

		sort(articulation_points.rbegin(), articulation_points.rend());

		for (int i = 0; i < m; i++) {
			printf("%d %d\n", -articulation_points[i].second, articulation_points[i].first);
		}
	}

	return 0;
}