#include <cstdio>

int main() {
	//freopen("input.txt", "r", stdin);
	unsigned int test_cases, degree, coef[25], d, k, cnt;
	unsigned long long int pol, exp_pol;

	scanf("%d", &test_cases);
	for (unsigned int test_id = 1; test_id <= test_cases; test_id++) {
		scanf("%d", &degree);
		for (unsigned int i = 0; i <= degree; i++)
			scanf("%d", &coef[i]);
		scanf("%d %d", &d, &k);

		cnt = 0;
		while (d * cnt * (cnt + 1) < k * 2) // 0 <= n < cnt . sum i = 1 to n of i*d <= k
			cnt++;

		pol = 0;
		exp_pol = 1;
		for (unsigned int i = 0; i <= degree; i++) {
			pol += exp_pol * coef[i];
			exp_pol *= cnt;
		}
		printf("%llu\n", pol);
	}
	return 0;
}
// d, 2d, 3d, 4d, ...
// sum i = 1 to n of i*d <= k < sum i = 1 to n+1 of i*d
// sum i = 1 to n of i*d = d + 2*d + 3*d + ... + n*d = d*(1+2+...+n) = d*n*(n+1)/2
// d*n*(n+1)/2 <= k < d*(n+1)*(n+2)/2
// n*(n+1) <= 2k/d < (n+1)*(n+2)
// n*n + n <= 2k/d < n*n + 3n + 2
// delta = 1 + 8k/d
// n = (-1 +- sqrt(1+8k/d))/2