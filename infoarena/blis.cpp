/*
dp[i][j] = lungimea celui mai lung subsir crescator format folosind primii i biti avand cel mai mare element j

dp[i][j] -> dp[i + p][j + bin(i, i + p)]
p <- [1..k]

dp[i][j] = max {dp[i - p][j - bin(i - p, i)] | p <- [1..k]}
dp[i][j] = max {dp[i - 1][j - bin(i - 1, i)], dp[i - 2][j - bin(i - 2, i)], dp[i - 3][j - bin(i - 3, i)], ..., dp[i - k + 1][j - bin(i - k + 1, i)]}

dp[i + 1][j]

*/


#include <cstdio>

int main() {
	freopen("blis.in", "r", stdin);
	freopen("blis.out", "w", stdout);

	int k, n;
	char str[100005];

	scanf("%d\n%s", &k, str);
	n = strlen(str);

	return 0;
}