#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int height, up, down, fatigue, currentHeight, day;
	while (scanf("%d %d %d %d", &height, &up, &down, &fatigue), height != 0)
	{
		fatigue *= up;
		up *= 100;
		down *= 100;
		height *= 100;
		currentHeight = 0;
		day = 0;
		while ((currentHeight >= 0) && (currentHeight <= height))
		{
			//printf("problem: %d %d %d %d\n", height, up, down, fatigue);
			day++;
			currentHeight += up;
			if (currentHeight <= height)
				currentHeight -= down;
			up -= fatigue;
			if (up < 0)
				up = 0;
		}
		if (currentHeight > 0)
			printf("success on day %d\n", day);
		else
			printf("failure on day %d\n", day);
	}
	return 0;
}