#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);
	int q, x, y, qx, qy;
	while (scanf("%d", &q), q != 0)
	{
		scanf("%d %d", &x,&y);
		for (int i = 0; i < q; i++)
		{
			scanf("%d %d", &qx, &qy);
			if ((qx == x) || (qy == y))
				printf("divisa\n");
			else if ((qx > x) && (qy > y))
				printf("NE\n");
			else if ((qx < x) && (qy > y))
				printf("NO\n");
			else if ((qx > x) && (qy < y))
				printf("SE\n");
			else if ((qx < x) && (qy < y))
				printf("SO\n");
		}
	}
	return 0;
}