#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

inline int reverseColor(int c) {
	return 1 - c;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n, m; // n vertices, m edges
	int x, y; // edge
	do {
		scanf("%d", &n);
		if (n != 0) {
			bool bipartite = true;
			vi adj[205];
			int color[205] = {0};
			queue<int> q;
			scanf("%d", &m);
			for (int i = 0; i < m; i++) {
				scanf("%d %d", &x, &y);
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
			for (int i = 0; i < n; i++)
				color[i] = -1;
			color[0] = 0;
			q.push(0);
			while (q.empty() == false) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < adj[u].size(); i++) {
					int v = adj[u][i];
					if (color[v] == -1) {
						color[v] = 1 - color[u];
						q.push(v);
					} else if (color[u] == color[v])
						bipartite = false;
				}
			}
			printf("%s.\n", bipartite ? "BICOLORABLE" : "NOT BICOLORABLE");
		}
	} while (n != 0);
	return 0;
}
