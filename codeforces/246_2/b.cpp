#include <cstdio>

int main() {
	int n, home_color[100005], away_color[100005], count_home_color[100005];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &home_color[i], &away_color[i]);
		count_home_color[home_color[i]]++;
	}

	for (int i = 0; i < n; i++) {
		int home_matches = n - 1 + count_home_color[away_color[i]];
		int away_matches = 2 * (n - 1) - home_matches;

		printf("%d %d\n", home_matches, away_matches);
	}

	return 0;
}