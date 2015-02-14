#include <unordered_set>
#include <limits>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n, x0, y0;
	vector<pair<int, int>> points;
	cin >> n >> x0 >> y0;
	for (int i = 0; i < n; i++) {
		pair<int, int> point;
		cin >> point.first >> point.second;
		points.push_back(point);
	}

	int shots = 0;
	unordered_set<double> slopes;
    double infiniteSlope = numeric_limits<double>::max();
	for (pair<int, int> point : points) {
		int dx = point.first - x0;
		int dy = point.second - y0;
		double slope = infiniteSlope;
		if (dx != 0)
			slope = static_cast<double>(dy) / static_cast<double>(dx);
		slopes.insert(slope);
	}

	cout << slopes.size() << endl;

	return 0;
}