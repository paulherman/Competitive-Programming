#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

struct Point {
    int x, y;
};

int maxPoints(vector<Point> &points) {
    double infiniteSlope = numeric_limits<double>::max();
                     
    int maxPointsOnLine = 0;
    if (points.size() > 0) {
        maxPointsOnLine = 1;
        for (int i = 0; i < points.size(); i++) {
            Point origin = points[i];
            unordered_map<double, int> slopePoints;
            int originCount = 1;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    Point other = points[j];
                    int pointsOnLine = 0;
                    if (origin.x == other.x && origin.y == other.y) {
                         originCount++;
                        pointsOnLine = originCount;
                    } else {
                         int dy = other.y - origin.y;
                         int dx = other.x - origin.x;

                         double slope = 0.0;
                         if (dx == 0) {
                             slope = infiniteSlope;
                         } else {
                             slope = static_cast<double>(dy) / static_cast<double>(dx);
                         }
                         if (slopePoints.find(slope) == slopePoints.end())
                             slopePoints[slope] = 0;
                         slopePoints[slope]++;
                         pointsOnLine = slopePoints[slope] + originCount;
                     }

                     if (pointsOnLine > maxPointsOnLine)
                         maxPointsOnLine = pointsOnLine;
                }
            }
        }
    }
    return maxPointsOnLine;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        vector<Point> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;
        cout << maxPoints(points) << '\n';
    }
    return 0;
}
