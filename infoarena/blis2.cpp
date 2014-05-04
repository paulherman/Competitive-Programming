#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

char seq[100000];
int k, length, kmax, lmax, num;
set<int> lis;

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
int toInt(int begin, int end)
{
	unsigned int num = 0;
	for (int i = begin; i < end; i++)
		if (seq[i] == '1')
			num += 1 << (end - i - 1);
	return num;
}
int main()
{
	freopen("blis.in", "r", stdin);
	freopen("blis.out", "w", stdout);

	scanf("%d\n", &k);
	scanf("%s", seq);
	length = strlen(seq);

	for (int i = 0; i < length; i++)
		kmax = max(kmax, toInt(i, min(length, i + k)));

	if (length < 1000)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				num = toInt(i, j);
				set<int>::iterator it = lis.find(num);
			}
		}
	}

	printf("%d\n%d\n", kmax, lmax);
	return 0;
}

