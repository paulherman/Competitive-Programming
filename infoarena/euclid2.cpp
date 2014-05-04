#include <cstdio>

int main() {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	unsigned long long int a, b, r;
	int t;

	scanf("%d", &t);
	for (int i=0; i<t; i++) {
		scanf("%llu %llu", &a, &b);
		while (b != 0) {
			r = b;
			b = a % b;
			a = r;
		}
		printf("%llu\n", a);
	}
	return 0;
}
