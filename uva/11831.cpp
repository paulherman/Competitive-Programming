#include <cstdio>
#include <cstring>

bool valid_move(int x, int y, int n, int m, char arena[105][105]) {
	return !(x < 0 || y < 0 || y >= n || x >= m || arena[y][x] == '#');
}
char rotate(char instr, char curr) {
	if (instr == 'D') { // turn to right
		if (curr == 'N')
			return 'L';
		else if (curr == 'S')
			return 'O';
		else if (curr == 'L')
			return 'S';
		else if (curr == 'O')
			return 'N';
	} else if (instr == 'E') { // turn to left
		if (curr == 'N')
			return 'O';
		else if (curr == 'S')
			return 'L';
		else if (curr == 'L')
			return 'N';
		else if (curr == 'O')
			return 'S';
	}
	return 0;
}
void move(int *x, int *y, char o, int n, int m, char arena[105][105]) {
	int xp = *x;
	int yp = *y;

	if (o == 'N')
		yp--;
	else if (o == 'S')
		yp++;
	else if (o == 'L')
		xp++;
	else if (o == 'O')
		xp--;
	if (valid_move(xp, yp, n, m, arena)) {
		*x = xp;
		*y = yp;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int n, m, s, x, y, stickers;
	char arena[105][105], instr[50005], orient;
	do {
		scanf("%d %d %d", &n, &m, &s);
		if (n != 0 && m != 0 && s != 0) {
			stickers = 0;
			orient = 0;
			memset(arena, 0, sizeof(arena));
			memset(instr, 0, sizeof(instr));

			for (int i = 0; i < n; i++) {
				scanf("%s", arena[i]);

				for (int j = 0; j < m; j++) {
					if (arena[i][j] != '#' && arena[i][j] != '*' && arena[i][j] != '.') {
						y = i;
						x = j;
						orient = arena[i][j];
						arena[i][j] = '.';
					}
				}
			}
			scanf("%s", instr);

			//for (int i = 0; i < n; i++)
			//	printf("%s\n", arena[i]);

			for (int i = 0; instr[i] != 0; i++) {
				if (instr[i] == 'F')
					move(&x, &y, orient, n, m, arena);
				else
					orient = rotate(instr[i], orient);

				//printf("%d %d %c %c\n", y, x, orient, arena[y][x]);

				if (arena[y][x] == '*') {
					arena[y][x] = '.';
					stickers++;
				}
			}

			printf("%d\n", stickers);
		}
	} while (n != 0 && m != 0 && s != 0);
	return 0;
}