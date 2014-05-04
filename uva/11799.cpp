#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int tests, n, speed, maxSpeed;
	scanf("%d", &tests);
	for (int t = 1; t <= tests; t++)
	{
		scanf("%d", &n);
		maxSpeed = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &speed);
			if (speed > maxSpeed)
				maxSpeed = speed;
		}
		printf("Case %d: %d\n", t, maxSpeed);
	}
	return 0;
}