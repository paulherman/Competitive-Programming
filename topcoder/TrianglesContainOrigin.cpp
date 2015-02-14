#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class TrianglesContainOrigin {
public:
	long long count(vector<int> x, vector<int> y) {
		const int points = x.size();
		const double pi = 2.0 * acos(0);
		long long triangles = 0;
		vector<double> angles;

		for (int i = 0; i < points; i++) {
			double angle = atan2(static_cast<double>(y[i]), static_cast<double>(x[i]));
			if (angle < 0.0)
				angle += 2 * pi;

			angles.push_back(angle);
		}

		sort(angles.begin(), angles.end());


		// A triangle ABC contains the origin iff:
		// b - a < pi, c - b < pi, c - a < pi
		for (int i = 0; i < points; i++) {
			auto ca = lower_bound(angles.begin(), angles.end(), pi + angles[i]);
			for (int j = i + 1; j < points; j++) {
				auto cb = lower_bound(angles.begin(), angles.end(), pi + angles[j]);

				if (cb != angles.end() && ca != angles.end())
					triangles += cb - ca;
			}
		}

		return triangles;
	}
};