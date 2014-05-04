#include <cstdio>

int n, m, v[100001], logn;

int main()
{
	int tip, x, i, lg;	
	freopen("cautbin.in", "r", stdin);
	freopen("cautbin.out", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (logn = 1; logn <= n; logn <<= 1);
	scanf("%d", &m);
	for (; m > 0; m--)
	{
		scanf("%d %d", &tip, &x);
		if ((tip == 0) || (tip == 1))
		{
			for (lg = logn, i = 0; lg; lg >>= 1)
				if (i + lg <= n && v[i + lg] <= x)
					i += lg;
			if ((tip == 0) && (v[i] != x))
				printf("-1\n");
			else
				printf("%d\n", i);
		}
		else
		{
			for (lg = logn, i = n; lg; lg >>= 1)
				if (i - lg > 0 && v[i - lg] >= x)
					i -= lg;
			printf("%d\n", i);
		}
	}
	return 0;
}

