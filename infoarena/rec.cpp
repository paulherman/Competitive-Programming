#include <cstdio>
#include <iostream>

int main() {
	freopen("rec.in", "r", stdin);
	//freopen("rec.out", "w", stdout);

	int s, n, f, dp[1005][12005], count;

	scanf("%d %d %d", &s, &n, &f);

	s = s - n * f;
	for (int i = 0; i <= s; i++)
		dp[n][i] = 1;

	for (int i = n - 1; i > 0; i--)
		for (int j = s - i; j >= 0; j--)
			dp[i][j] = (dp [i + 1][j] + dp[i][j + i]) % 666013;

	count = 0;
	for (int i = 0; i <= s; i++)
		count = (count + dp[1][i]) % 666013;

	printf("%d\n", count);
	return count;
}