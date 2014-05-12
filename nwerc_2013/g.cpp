#include <cstdio>

int gcd(int x, int y) {
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int main() {
    int ab, ac, bd, at, div, top, bot;
    while (scanf("%d %d %d", &ab, &ac, &bd) == 3) {
        top = ac * ab;
        bot = bd - ac;
        div = gcd(top, bot);
        top /= div;
        bot /= div;
        printf("%d/%d\n", top, bot);
    }
    return 0;
}