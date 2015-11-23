#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

const double EPS = 1e-9;
struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(PT other) const {
      if (fabs(x - other.x) < EPS)
          return y < other.y;
      return x < other.x;
  }
};

double coord = 1000000000.0;
PT min_pt(-coord, -coord), max_pt(coord, coord);
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

pair<PT, PT> closest_points(vector<PT> &x, vector<PT> &y, int left, int right) {
    if (left >= right - 1)
        return make_pair(min_pt, max_pt);

    if (right - left == 2) {
        if (y[left + 1] < y[left])
            swap(y[left], y[left + 1]);
        return make_pair(y[left], y[left + 1]);
    }
    
    int mid = (left + right) / 2;
    auto pl = closest_points(x, y, left, mid);
    double dl = dist2(pl.first, pl.second);
    auto pr = closest_points(x, y, mid, right);
    double dr = dist2(pr.first, pr.second);
    
    pair<PT, PT> res;
    double dist = 0.0;
    if (dl < dr) {
        dist = dl;
        res = pl;
    } else {
        dist = dr;
        res = pr;
    }

    sort(y.begin() + left, y.begin() + right);
    vector<PT> v;
    for (int i = left; i < right; i++) 

        if (y[i].y - x[mid].x <= sqrt(dist))
            v.push_back(y[i]);

    for (int i = 0; i + 1 < v.size(); i++) {
        for (int j = i + 1; j < v.size() & j - i < 8; j++) {
            double can = dist2(v[i], v[j]);
            if (can < dist) {
                dist = can;
                res = make_pair(v[i], v[j]);
            }
        }
    }

    return res;
}

int main() {
    freopen("cmap.in", "r", stdin);
    freopen("cmap.out", "w", stdout);

    int n;
    cin >> n;
    vector<PT> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].x >> x[i].y;
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < n; i++)
        y[i] = PT(x[i].y, x[i].x);

    auto res = closest_points(x, y, 0, n);
    cout << fixed << setprecision(6) << sqrt(dist2(res.first, res.second)) << endl;

    return 0;
}
