#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, budget, hotels, weeks, hotelPrice, hotelPlace, bestPrice;
	while (scanf("%d %d %d %d", &n, &budget, &hotels, &weeks) != EOF)
	{
		bestPrice = budget + 1;
		for (int i = 0; i < hotels; i++)
		{
			scanf("%d", &hotelPrice);
			for (int j = 0; j < weeks; j++)
			{
				scanf("%d", &hotelPlace);
				if ((hotelPlace >= n) && (n * hotelPrice < bestPrice))
					bestPrice = n * hotelPrice;
			}
		}
		if (bestPrice <= budget)
			printf("%d\n", bestPrice);
		else
			printf("stay home\n");
	}
	return 0;
}