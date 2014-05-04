#include <cstdio>

int main()
{
	freopen("input.txt", "r", stdin);
	char c = 0;
	int quote = 0;
	while (scanf("%c", &c) != EOF) {
		if (c == '"') {
			if (quote == 0)
				printf("``");
			else
				printf("''");
			quote = (quote + 1) % 2;
		} else if (c != EOF)
			putchar(c);
	}
	return 0;
}