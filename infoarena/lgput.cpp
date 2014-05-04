#include <cstdio>

const long long int mod = 1999999973;

int main()
{
	freopen("lgput.in", "r", stdin);
	freopen("lgput.out", "w", stdout);
	long long int n, p, e;
	scanf("%lld %lld", &n, &p);
	e = 1;
	for (int i = 0; (1 << i) <= p; i++)
	{
		if ((p & (1 << i)) > 0)
			e = (e * n) % mod;
		n = (n * n) % mod;
	}
	printf("%lld", e);
	return 0;
}
