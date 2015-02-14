#include <cstdio>

typedef unsigned uint;

uint max(uint a, uint b) {
	if (a > b)
		return a;
	return b;
}

uint min(uint a, uint b) {
	if (a < b)
		return a;
	return b;
}

uint count(uint n) {
	uint res = 0;
	while (n != 1) {
		if (n % 2 == 1)
			n = n * 3 + 1;
		else 
			n /= 2;
		res++;
	}
	return res + 1;
}

int main()
{
	uint a, b, cycleMax, aCopy, bCopy;
	while (scanf("%d %d", &a, &b) != EOF) {
		aCopy = a;
		bCopy = b;
		a = min(aCopy, bCopy);
		b = max(aCopy, bCopy);
		cycleMax = 0;
		for (uint i = a; i <= b; i++)
			cycleMax = max(cycleMax, count(i));
		printf("%d %d %d\n", aCopy, bCopy, cycleMax);
	}
	return 0;
}
