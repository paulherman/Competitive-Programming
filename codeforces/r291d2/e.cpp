#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000007;
int *dp;
vector<int> nodes;

int cnt(int range) {
	if (dp[range] == -1) {
		dp[range] = 0;
		for (int d : nodes) {
			if (range - d >= 0)
				dp[range] += dp[range - d];
		}
	} else
		return dp[range];
}

int main() {
	int children, range;

	cin >> children >> range;
	for (int i = 0; i < children; i++) {
		int d;
		cin >> d;
		nodes.push_back(d);
	}

	dp = new int[mod];
	for (int i = 0; i <= range; i++)
		dp[i] = -1;
	dp[0] = 1;

	cnt(range);

	for (int i = 0; i <= range; i++)
		cout << dp[i] << endl;

	return 0;
}