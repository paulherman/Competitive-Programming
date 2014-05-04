#include <cstdio>

const int perioada_mod = 1332028;
const int mod = 666013;

int fibonacci(int n)
{
	int f0 = 0;
	int f1 = 1;
	int ft = 0;
	for (int i = 2; i <= n; i++)
	{
		ft = f0 + f1;
		f0 = f1 % mod;
		f1 = ft % mod;
	}
	if (n > 1)
		return ft % mod;
	else if (n == 1)
		return 1;
	else
		return 0;
}
int main()
{
	int n = 0;
	freopen("kfib.in", "r", stdin);
	freopen("kfib.out", "w", stdout);
	scanf("%d", &n);
	printf("%d", fibonacci(n % perioada_mod));
	return 0;
}

