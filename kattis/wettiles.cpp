#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
    int x, y;
    Node(int a, int b) {
        x = a;
        y = b;
    }
    Node operator+(Node other) {
        return Node(x + other.x, y + other.y);
    }
};

int map[1005][1005];
const Node dirs[] = {
    Node(-1, 0),
    Node(1, 0),
    Node(0, -1),
    Node(0, 1)
};
int width, height, max_dist, num_leaks, num_walls;

bool is_valid(Node node) {
    int x = node.x;
    int y = node.y;
    if (x < 1)
        return false;
    if (x > width)
        return false;
    if (y < 1)
        return false;
    if (y > height)
        return false;
    if (map[x][y] == -1)
        return false;
    return map[x][y] == 1005 * 1005;
}

void wall(int x0, int y0, int x1, int y1) {
    if (x0 == x1) {
        if (y0 > y1)
            swap(y0, y1);

        for (int i = y0; i <= y1; i++)
            map[x0][i] = -1;
    } else if (y0 == y1) {
        if (x0 > x1)
            swap(x0, x1);
        for (int i = x0; i <= x1; i++)
            map[i][y0] = -1;
    } else {
        int dx = 0;
        int dy = 0;
        if (x0 > x1)
            dx = -1;
        else
            dx = 1;

        if (y0 > y1)
            dy = -1;
        else
            dy = 1;
        while (x0 != x1 && y0 != y1) {
            map[x0][y0] = -1;
            x0 += dx;
            y0 += dy;
        }
        map[x0][y0] = -1;
    }
}

int main() {
    while (true) {
        cin >> width;
        if (width == -1)
            break;

        queue<Node> bfs;
        for (int i = 0; i < 1005; i++)
            for (int j = 0; j < 1005; j++)
                map[i][j] = 1005 * 1005;

        cin >> height >> max_dist >> num_leaks >> num_walls;

        for (int i = 0; i < num_leaks; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
            bfs.push(Node(x, y));
        }

        for (int w = 0; w < num_walls; w++) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            wall(x0, y0, x1, y1);
        }

        int count = 0;
        while (!bfs.empty()) {
            Node node = bfs.front();
            bfs.pop();
            if (map[node.x][node.y] <= max_dist)
                count++;

            for (int i = 0; i < 4; i++) {
                Node next = node + dirs[i];
                if (is_valid(next)) {
                    map[next.x][next.y] = map[node.x][node.y] + 1;
                    if (map[next.x][next.y] <= max_dist) {
                        bfs.push(next);
                    }
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}
