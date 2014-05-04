#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct muchie
{
	int a, b, c;
	bool apm;
};

int n, m, p, muchii_adaugate, cost, componente, inaltime[10001], tati[10001];
vector<muchie> muchii;
bool vizitat[10001];

inline bool comparare(muchie a, muchie b)
{
	return a.c < b.c;
}
inline int cauta(int x)
{
	while (tati[x] != x)
		x = tati[x];
	return x;
}
inline void reuneste(int x, int y)
{
	if (inaltime[x] > inaltime[y])
		tati[y] = x;
	else if (inaltime[y] > inaltime[x])
		tati[x] = y;
	else
	{
		tati[x] = y;
		inaltime[y]++;
	}
}
inline void citire()
{
	freopen("flood.in", "r", stdin);
	int a, b, ta, tb;
	muchie t;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		tati[i] = i;
		inaltime[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		ta = cauta(a);
		tb = cauta(b);
		if (ta != tb)
			reuneste(ta, tb);
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++)
	{
		scanf("%d %d %d", &t.a, &t.b, &t.c);
		t.apm = false;
		muchii.push_back(t);
	}
}
inline void scriere()
{
	freopen("flood.out", "w", stdout);
	printf("%d\n%d\n", muchii_adaugate, cost);
	for (int i = 0; i < muchii.size(); i++)
		if (muchii[i].apm == true)
			printf("%d %d %d\n", muchii[i].a, muchii[i].b, muchii[i].c);
}
inline void componente_conexe()
{
	componente = 0;
	for (int i = 1; i <= n; i++)
	{
		int radacina = cauta(i);
		if (vizitat[radacina] == false)
		{
			vizitat[radacina] = true;
			componente++;
		}
	}
}
inline void apm()
{
	sort(muchii.begin(), muchii.end(), comparare);
	muchii_adaugate = 0;
	int muchie_curenta = 0;
	int ra, rb;
	while (muchii_adaugate < componente - 1)
	{
		ra = cauta(muchii[muchie_curenta].a);
		rb = cauta(muchii[muchie_curenta].b);
		if (ra != rb)
		{
			muchii[muchie_curenta].apm = true;
			muchii_adaugate++;
			cost += muchii[muchie_curenta].c;
			reuneste(ra, rb);
		}
		muchie_curenta++;
	}
}
int main()
{
	citire();
	componente_conexe();
	apm();
	scriere();
	return 0;
}

