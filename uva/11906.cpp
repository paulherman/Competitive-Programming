#include <cstdio>
#include <queue>

using namespace std;

bool valid_move(int x, int y, int dx, int dy, int grid[105][105], int r, int c) {
	int xp = x + dx;
	int yp = y + dy;

	// check boundaries
	if (xp < 0 || yp < 0 || xp >= c || yp >= r)
		return false;

	// check water
}

void solution(int test_id) {
	int r, c, m, n, w, grid[105][105];
	scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
	for (int i = 0; i < w; i++) {
		int w_x, w_y;
		scanf("%d %d", &w_x, &w_y);
		grid[w_y - 1][w_x - 1] = -1;
	}
}

int main() {
	int test_cases;
	scanf("%d", &test_cases);

	for (int i = 1; i <= test_cases; i++)
		solution(i);

	return 0;
}