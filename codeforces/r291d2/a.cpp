#include <iostream>
using namespace std;

int main() {
	string number;
	cin >> number;
	for (int i = 0; i < number.length(); i++) {
		char digit = '9' - number[i] + '0';
		if (i == 0 && digit != '0' && digit < number[i]) {
			number[i] = digit;
		} else if (i > 0 && digit < number[i]) {
			number[i] = digit;
		}
	}
	cout << number;
	return 0;
}