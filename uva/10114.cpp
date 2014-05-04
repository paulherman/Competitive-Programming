#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int months, depreciationSize, now;
	float down, loan, value, payPerMonth, depreciation[105];
	while (scanf("%d %f %f %d", &months, &down, &loan, &depreciationSize), months >= 0)
	{
		for (; depreciationSize > 0; depreciationSize--)
		{
			int dm; float dp;
			scanf("%d %f", &dm, &dp);
			dp = 1 - dp;
			for (int i = dm; i <= 100; i++)
				depreciation[i] = dp;
		}
		payPerMonth = loan / (float)months;
		value = depreciation[0] * (down + loan);
		now = 0;
		while (loan > value)
		{
			now++;
			loan -= payPerMonth;
			value *= depreciation[now];
		}
		if (now == 1)
			printf("1 month\n");
		else
			printf("%d months\n", now);
	}
	return 0;
}