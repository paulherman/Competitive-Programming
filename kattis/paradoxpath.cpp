#include <set>
#include <utility>
#include <cassert>

int FindPath(const int startX, const int startY, const int targetX, const int targetY, const unsigned char *map, const int width, const int height, const int *path; const int maxPathLength) {
  assert(width > 0 && height > 0);
  assert(startX >= 0 && startX < width && startY >= 0 && startY < height);
  assert(targetX >= 0 && targetX < height && targetY >= 0 && targetY < height);
  assert(maxPathLength >= 0);
  assert(map[startY * width + startX] == 0 && map[targetY * width + targetX] == 0);
}
