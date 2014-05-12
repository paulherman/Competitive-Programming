#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m, weight[500], visited[500], max_weight, adjm[500][500];
vector<int> adj[500];

bool is_connected(vector<int> &prev, int node) {
    for (int i = 0; i < (int)prev.size(); i++)
        if (adjm[prev[i]][node] == 0)
            return false;
    return true;
}
int dfs(int u, int depth, vector<int> &prev) {
    if (depth == 4)
        return 0;
    int max_dfs_weight = 0;
    prev.push_back(u);
    visited[u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (visited[v] == 0 && is_connected(prev, v)) {
            max_dfs_weight = max(max_dfs_weight, dfs(v, depth + 1, prev));
        }
    }
    visited[u] = 0;
    prev.pop_back();
    return weight[u] + max_dfs_weight;
}
int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        max_weight = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            memset(adjm[i], 0, sizeof(adjm[i]));
            adj[i].clear();
            scanf("%d", &weight[i]);
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adjm[u][v] = adjm[v][u] = 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            vector<int> prev;
            max_weight = max(max_weight, dfs(i, 0, prev));
        }

        printf("%d\n", max_weight);
    }
    return 0;
}