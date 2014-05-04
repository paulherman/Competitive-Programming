#include <cstdio>
#include <iostream>
using namespace std;

const int oo = 0x3f3f3f;
int padure[1001][1001];
int cost[1001][1001];
int n, m, pc, pl, cc, cl;

void bfs(int i, int j, int c)
{
	if (cost[i][j] > c)
	{
		cost[i][j] = c;
		if ((i - 1) > 0)
		{
			if (padure[i - 1][j] != padure[i][j])
				bfs(i - 1, j, cost[i][j] + 1);
			else
				bfs(i - 1, j, cost[i][j]);
		}
		if ((j - 1) > 0)
		{
			if (padure[i][j - 1] != padure[i][j])
				bfs(i, j - 1, cost[i][j] + 1);
			else
				bfs(i, j - 1, cost[i][j]);
		}
		if ((i + 1) <= n)
		{
			if (padure[i + 1][j] != padure[i][j])
				bfs(i + 1, j, cost[i][j] + 1);
			else
				bfs(i + 1, j, cost[i][j]);
		}
		if ((j + 1) <= m)
		{
			if (padure[i][j + 1] != padure[i][j])
				bfs(i, j + 1, cost[i][j] + 1);
			else
				bfs(i, j + 1, cost[i][j]);
		}
	}
}
int main()
{
	freopen("padure.in", "r", stdin);
	freopen("padure.out", "w", stdout);
	cin >> n >> m >> pl >> pc >> cl >> cc;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> padure[i][j];
			cost[i][j] = oo;
		}
	}
	bfs(pl, pc, 0);
	cout << cost[cl][cc] << "\n";
	return 0;
}
