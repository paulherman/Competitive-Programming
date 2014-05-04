#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	int v[3] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &v[0], &v[1], &v[2]);
		sort(v, v + 3);
		printf("Case %d: %d\n", i, v[1]);
	}
	return 0;
}