#include <iomanip>
#include <limits>
#include <iomanip>
#include <limits>
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

struct PT {
    double lat, lon;
};

const double pi = 3.14159265358979323846;

double toRadians(double degs) {
    double res = degs * pi / 180.0;
    while (res < 0)
        res += 2 * pi;
    return res;
}
double dist(PT c1, PT c2) {
    double R = 6372.797560856; // earth radius in km
    double la1_r = toRadians(c1.lat);
    double la2_r = toRadians(c2.lat);
    double delta1 = toRadians(c2.lat-c1.lat);
    double delta2 = toRadians(c2.lon-c1.lon);

    double latH = sin(delta1*0.5);
    latH *= latH; // squared
    double lonH = sin(delta2*0.5);
    lonH *= lonH; //squared 

    double tmp = cos(la1_r)*cos(la2_r);
    return 2*R*asin(sqrt(latH + tmp*lonH));
}

int main() {
    int n;
    while (cin >> n) {
        vector<PT> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].lat >> points[i].lon;
        }
        
        double md = numeric_limits<double>::max();
        int p = -1;
        for (int i = 0; i < n; i++) {
            double mfd = 0.0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    double d = dist(points[i], points[j]);
                    if (d > mfd)
                        mfd = d;
                }
            }
            if (mfd < md) {
                p = i;
                md = mfd;
            }
        }

        assert(p != -1);
        cout << setprecision(2) << fixed << points[p].lat << ' ' << points[p].lon << '\n';
    }
    return 0;
}
