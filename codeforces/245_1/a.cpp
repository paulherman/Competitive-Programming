#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[100005], picks;
int n, init[100005], goal[100005];

void dfs(int u, int p, int depth, int change_even, int change_odd) {
	if (depth % 2 == 0) {
		int value = (init[u] + change_even) % 2;
		if (value != goal[u]) {
			change_even++;
			picks.push_back(u);
		}
	} else {
		int value = (init[u] + change_odd) % 2;
		if (value != goal[u]) {
			change_odd++;
			picks.push_back(u);
		}
	}

	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (p != v)
			dfs(v, u, depth + 1, change_even, change_odd);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;

		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &init[i]);

	for (int i = 1; i <= n; i++)
		scanf("%d", &goal[i]);

	dfs(1, 0, 0, 0, 0);

	printf("%d\n", (int)picks.size());

	for (int i = 0; i < (int)picks.size(); i++)
		printf("%d\n", picks[i]);

	return 0;
}