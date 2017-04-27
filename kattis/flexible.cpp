#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int width = 0, numWalls = 0;
  cin >> width >> numWalls;

  vector<int> walls(numWalls + 2);
  walls[0] = 0;
  walls[numWalls + 1] = width;
  for (int i = 0; i < numWalls; i++) {
    cin >> walls[i + 1];
  }

  set<int> lengths;
  for (int wall0 : walls) {
    for (int wall1 : walls) {
      if (wall0 < wall1) {
        lengths.insert(wall1 - wall0);
      }
    }
  }

  for (int length : lengths) {
    cout << length << " ";
  }

  return 0;
}
