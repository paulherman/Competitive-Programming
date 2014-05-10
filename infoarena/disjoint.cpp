#include <cstdio>

const int MAX_SETS = 100005;

int set_search(int set_parent[MAX_SETS], int e) {
	int root = e;
	while (set_parent[root] != root)
		root = set_parent[root];
	while (e != root) { // path compression
		int e_parent = set_parent[e];
		set_parent[e] = root;
		e = e_parent;
	}
	return root;
}

void set_union(int set_parent[MAX_SETS], int set_height[MAX_SETS], int x, int y) {
	int set_x = set_search(set_parent, x);
	int set_y = set_search(set_parent, y);
	if (set_height[set_x] > set_height[set_y])
		set_parent[set_y] = set_x;
	else if (set_height[set_x] < set_height[set_y])
		set_parent[set_x] = set_y;
	else {
		set_parent[set_y] = set_x;
		set_height[set_x] += 1;
	}
}

void set_init(int set_parent[MAX_SETS], int set_height[MAX_SETS], int set_count) {
	for (int i = 1; i <= set_count; i++) {
		set_parent[i] = i;
		set_height[i] = 1;
	}
}

int main() {
	freopen("disjoint.in", "r", stdin);
	freopen("disjoint.out", "w", stdout);

	int set_count, query_count, set_parent[MAX_SETS], set_height[MAX_SETS];

	scanf("%d %d", &set_count, &query_count);
	set_init(set_parent, set_height, set_count);

	for (int i = 0; i < query_count; i++) {
		int query_type, x, y;
		scanf("%d %d %d", &query_type, &x, &y);
		if (query_type == 1) // union
			set_union(set_parent, set_height, x, y);
		else { // same set?
			if (set_search(set_parent, x) == set_search(set_parent, y))
				printf("DA\n");
			else
				printf("NU\n");
		}
	}

	return 0;
}