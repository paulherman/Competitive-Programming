#include <cstdio>
#include <cmath>
using namespace std;

int n, m, po, pv, xa, ya, xb, yb, v[2000][2], o[2000][2], dx, dy, br, sv, so;
double dist;

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int between(int a, int b, int x, int y)
{
	if (max(a, b) <= min(x, y)) //A is left of B
		return 0;
	if (min(a, b) >= max(x, y)) //A is right of B
		return 0;
	if ((min(a, b) >= min(x, y)) && (max(a, b) <= min(x, y))) //A in B
		return abs((double)(a - b));
	if ((min(a, b) <= min(x, y)) && (max(a, b) >= max(x, y))) //B in A
		return abs((double)(x - y));
	if ((min(a, b) <= max(x, y)) && (max(a, b) >= max(x, y)))
		return abs((double)(min(a, b) - max(x, y)));
	if ((max(a, b) >= min(x, y)) && (min(a, b) <= min(x, y)))
		return abs((double)(max(a, b) - min(x, y)));
	return 0;
}
int main()
{
	freopen("parc.in", "r", stdin);
	freopen("parc.out", "w", stdout);
	scanf("%d %d\n", &n, &m);
	scanf("%d %d %d %d\n", &xa, &ya, &xb, &yb);
	scanf("%d\n", &pv);

	dx = abs((double)(xb - xa));
	dy = abs((double)(yb - ya));

	for (int i = 0; i < pv; i++)
	{
		scanf("%d %d\n", &v[i][0], &v[i][1]);
		br = between(xa, xb, v[i][0], v[i][1]);
		if ((br > 0) || (min(xa, xb) == max(v[i][0], v[i][1])) || (max(xa, xb) == min(v[i][0], v[i][1])))
			sv++;
		dist += (double)br;
		dx -= br;
	}
	scanf("%d\n", &po);
	for (int i = 0; i < po; i++)
	{
		scanf("%d %d\n", &o[i][0], &o[i][1]);
		br = between(ya, yb, o[i][0], o[i][1]);
		if ((br > 0) || (min(ya, yb) == max(o[i][0], o[i][1])) || (max(ya, yb) == min(o[i][0], o[i][1])))
			so++;
		dist += (double)br;
		dy -= br;
	}
	so--;
	sv--;
	dist += sqrt(dx * dx + dy * dy);
	printf("%.06f\n", dist);
	printf("%d\n", (so * (so + 1)) / 2 + (sv * (sv + 1)) / 2);
	return 0;
}
