#include <fstream>
using namespace std;

int main() {
	freopen("adunare.in", "r", stdin);
	freopen("adunare.out", "w", stdout);

	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", a + b);

	return 0;
}

