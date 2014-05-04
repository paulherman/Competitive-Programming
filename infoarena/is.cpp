#include <iostream>
using namespace std;

int ways[100001][100001];

int bkt(int b, int m)
{
	if (b > m)
		return 0;
	if ((m == 0) || (b == 0))
		return 1;
	if (ways[b][m] != -1)
		return ways[b][m];
	for (int i = m - 1; i >= 0; i--)
		for (int j = b - 1; j >= 0; j--)
				ways[b][m] += bkt(j, i);
	return ways[b][m];
}
int main()
{
	int n = 0;
	cin >> n;
	cout << bkt(n, n);
}
