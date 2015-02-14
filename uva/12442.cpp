#include <cstdio>
#include <cstring>

void dfs(int u, int *g, int *vis, int *cnt)
{
	vis[u] = 1;
	if (vis[g[u]] == 0 && g[u] != 0) {
		dfs(g[u], g, vis, cnt);
		cnt[u] = 1 + cnt[g[u]];
	}
	vis[u] = 0;

	//printf("cnt[%d] = %d\n", u, cnt[u]);
}

void test_case(int test_id) {
	int n, g[50005], cnt[50005], vis[50005], node;

	node = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		g[i] = 0;
		cnt[i] = -1;
		vis[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u] = v;
	}

	for (int u = 1; u <= n; u++) {
		if (cnt[u] == -1)
			dfs(u, g, vis, cnt);

		if (cnt[u] > cnt[node])
			node = u;
	}

	printf("Case %d: %d\n", test_id, node);
}

int main() {
	int tests = 0;

	scanf("%d", &tests);

	for (int test_id = 1; test_id <= tests; test_id++)
		test_case(test_id);

	return 0;
}
