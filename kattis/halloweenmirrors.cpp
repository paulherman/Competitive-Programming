#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; };

PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
bool ProjectionIsOnSegment(PT x, PT a, PT b) {
    PT y = ProjectPointLine(a, b, x);
    return DistancePointSegment(a, b, y) < EPS;   
}

int main() {
    int mirrors, positions;
    
    while (cin >> mirrors) {
        if (mirrors == 0)
            break;
        
        vector<pair<PT, PT>> ms;
        for (int i = 0; i < mirrors; i++) {
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            ms.push_back(make_pair(PT(x0, y0), PT(x1, y1))); 
        }

        cin >> positions;
        for (int i = 0; i < positions; i++) {
            int ans = 0;
            int x, y;
            cin >> x >> y;
            for (int j = 0; j < mirrors; j++)
                if (ProjectionIsOnSegment(PT(x, y), ms[j].first, ms[j].second))
                    ans++;
            cout << ans << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}
