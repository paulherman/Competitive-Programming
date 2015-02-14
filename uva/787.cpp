#include <iostream>
#include <vector>
#include <limits>
using namespace std;

long long maxProduct(const vector<int> &numbers) {
	long long maxPositive = numeric_limits<long long>::min();
	long long minPositive = numeric_limits<long long>::max();
	long long minCurrent = numeric_limits<long long>::min();
	long long maxCurrent = numeric_limits<long long>::max();

	for (int i = 0; i < numbers.size(); i++) {
		int number = numbers[i];


	}

	return maxPositive;
}

int main() {
	while (!cin.eof()) {
		vector<int> numbers;
		int number;
		do {
			cin >> number;
			numbers.push_back(number);
		} while (number != -999999);
		numbers.pop_back();
		cout << maxProduct(numbers) << endl;
	}
	return 0;
}