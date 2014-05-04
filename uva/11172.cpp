#include <cstdio>

int main()
{
	int n = 0;
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%s\n", a == b ? "=" : (a < b ? "<" : ">"));
	}
	return 0;
}