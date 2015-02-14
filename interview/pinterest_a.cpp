#include <cstdio>
#include <vector>
using namespace std;

vector<int> look_and_say(vector<int> num) {
	vector<int> cnt;
	int n = (int)num.size();

	for (int b = 0; b < n; ) {
		int digit = num[b], k = 0;

		for (; b < n && digit == num[b]; k++, b++);

		cnt.push_back(k);
		cnt.push_back(digit);
	}

	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);

	vector<int> num;
	int n = 0;

	scanf("%d", &n);
	num.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	vector<int> v = look_and_say(num);
	for (int i = 0; i < (int)v.size(); i++)
		printf("%d ", v[i]);

	return 0;
}