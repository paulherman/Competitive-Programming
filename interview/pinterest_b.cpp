int priority(char op) {
	if (op == '-' || op == '+')
		return 0;
	return 1;
}

int digitToInt(char digit) {
	return digit - '0';
}

bool isDigit(char c) {
	return '0' <= digit && digit <= '9';
}

int eval(string expr) {
	stack<int> num;
	stack<char> op;

	for (int i = 0; i < expr.length(); i++) {
		char c = expr[i];
		if (isDigit(c))
			num.push(toDigit(c));
		else {
		}
	}

	return num.top();
}

int main() {
	return 0;
}