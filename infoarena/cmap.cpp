#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long int n, ps;
long double dmin;
pair<long long int, long long int> x[100001], y[100001], patrat[100001];

inline void citire()
{
	freopen("cmap.in", "r", stdin);
	scanf("%lld", &n);
	for (long long int i = 0; i < n; i++)
		scanf("%lld %lld", &x[i].first, &x[i].second);
}
inline void scriere()
{
	freopen("cmap.out", "w", stdout);
	printf("%.6Lf\n", dmin);
}
inline long long int sqdist(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
long long int dist(long long int s, long long int d)
{
	if (d - s == 2)
	{
		if (y[s] > y[s + 1])
			swap(y[s], y[s + 1]); //Sortam punctele dupa oY
		return sqdist(x[s], x[s + 1]);
	}
	else if (s >= d - 1)
		return 0x3f3f3f;
	else
	{
		long long int m = (s + d) / 2; //Calculam jumatatea sirului
		long long int temp_dist = min(dist(s, m), dist(m, d)); //Distanta minima din cele doua jumatati
		sort(y + s, y + d); //Sortam punctele dupa oY
		ps = 0;
		for (long long int i = s; i < d; i++)
			if (abs(y[i].second - x[m].first) <= temp_dist)	//Punctul se afla la o distanta mai mica de temp_dist
			{
				patrat[ps] = y[i];
				ps++;
			}
		for (long long int i = 0; i < ps - 1; i++)
			for (long long int j = i + 1; (j < ps) && (j - i < 8); j++)
				temp_dist = min(temp_dist, sqdist(patrat[i], patrat[j]));
		return temp_dist;
	}
}
inline void rezolvare()
{
	sort(x, x + n);
	for (long long int i = 0; i < n; i++)
		y[i] = make_pair(x[i].second, x[i].first);
	dmin = sqrt(dist(0, n));
}
int main()
{
	citire();
	rezolvare();
	scriere();
	return 0;
}

