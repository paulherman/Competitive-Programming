#include <cstdio>


int main()
{
	freopen("lgput.in", "r", stdin);
	freopen("lgput.out", "w", stdout);

	const long long int mod = 1999999973;
	long long int n, p, e;

	scanf("%lld %lld", &n, &p);

	e = 1;
	while (p != 0) {
		if (p % 2 == 1)
			e = (e * n) % mod;
		n = (n * n) % mod;
		p /= 2;
	}

	printf("%lld", e);
	return 0;
}
