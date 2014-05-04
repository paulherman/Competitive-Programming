#include <cstdio>
#include <cstring>

int main() {
	const int coins[] = { 1, 5, 10, 25, 50 };
	const int coins_size = 5;
	unsigned long long int change, dp[30005];
	while (scanf("%d", &change) == 1) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < coins_size; i++)
			for (int j = coins[i]; j <= change; j++)
				dp[j] += dp[j - coins[i]];
		if (dp[change] == 1)
			printf("There is only %llu way to produce %d cents change.\n", dp[change], change);
		else
			printf("There are %llu ways to produce %d cents change.\n", dp[change], change);
	}
	return 0;
}