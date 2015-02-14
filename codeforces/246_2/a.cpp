#include <cstdio>

int main() {
	int n, k, eligible_members;

	eligible_members = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int years = 0;
		scanf("%d", &years);
		if (years + k <= 5)
			eligible_members++;
	}

	printf("%d\n", eligible_members / 3);

	return 0;
}