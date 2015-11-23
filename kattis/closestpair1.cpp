#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>
#include <set>
using namespace std;

const double EPS = 1e-9;

struct PT {
  double x, y;
  PT(double x, double y) : x(x), y(y) {}
  PT() { }
};

inline double dist(PT a, PT b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y,2));
}

struct comparison_vertical {
	bool operator()(const PT &a, const PT &b) const {
		if (fabs(a.y - b.y) < EPS)
			return a.x < b.x;
		return a.y < b.y;
	}
};

bool comparison_horizontal(PT a, PT b) {
	if (fabs(a.x - b.x) < EPS)
		return a.y < b.y;
    return a.x < b.x;
}



int main() {
    int n = 0;

    while (cin >> n) {
        if (n == 0)
            break;

		vector<PT> points(n);

        for (int i = 0; i < n; i++)
			cin >> points[i].x >> points[i].y;

        sort(points.begin(), points.end(), comparison_horizontal);

        PT p0, p1;
        double min_dist = 300000.0;
        set<PT, comparison_vertical> candidates; // Set of candidate points within min_dist on X axis from current point
        int left_range = 0;

        for (PT p : points) {
			while (p.x - points[left_range].x > min_dist) {
				candidates.erase(points[left_range]);
				left_range++;
			}

			// Get the points within min_dist on Y axis and within min_dist on X axis from current point
			PT low(p.x, p.y - min_dist), high(p.x, p.y + min_dist);
			auto low_it = candidates.lower_bound(low);
			auto high_it = candidates.upper_bound(high);

			for (auto it = low_it; it != high_it; it++) {
				double candidate_dist = dist(*it, p);
				if (candidate_dist < min_dist) {
					min_dist = candidate_dist;
					p0 = p;
					p1 = *it;
				}
			}

			candidates.insert(p);
		}

        cout << setprecision(2) << fixed << p0.x << ' ' << p0.y << ' ' << p1.x << ' ' << p1.y << '\n';
    }
    return 0;
}

