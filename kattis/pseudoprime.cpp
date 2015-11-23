#include <iostream>
#include <cmath>
using namespace std;

int res(long long int n, long long int p) {
    long long int mod = p;
	long long int e = 1;
	while (p != 0) {
		if (p % 2 == 1)
			e = (e * n) % mod;
		n = (n * n) % mod;
		p /= 2;
	}
    return e;
}
bool prime(int n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    int d = 3;
    int lim = sqrt(n) + 1;
    while (d < lim) {
        if (n % d == 0)
            return false;
        d += 2;
    }
    return true;
}
int main() {
    int p, a;
    while (cin >> p >> a) {
        if (p == 0 && a == 0)
            break;
        if (res(a, p) == a && !prime(p))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
