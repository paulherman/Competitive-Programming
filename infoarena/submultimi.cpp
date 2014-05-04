#include <cstdio>

int multime[17];
int n;

void bkt(int p, int s)
{
	if (p == s)
	{
		for (int i = 1; i < s; i++)
			printf("%d ", multime[i]);
		printf("\n");
	}
	else
		for (int i = multime[p - 1] + 1; i <= n; i++)
		{
			multime[p] = i;
			bkt(p + 1, s);
		}
}
int main()
{
	freopen("submultimi.in", "r", stdin);
	freopen("submultimi.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		bkt(1, i + 1);
	return 0;
}

