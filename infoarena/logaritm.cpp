/*
 * Autor: Paul Herman
 * Problema: logaritm natural
 * Data: 14.10.2011
 */
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double ln(double x)
{
	double dx = min(1.0, x);
	x = max(1.0, x);
	double result = 0.0;
	while (dx < x)
	{
		result += 1 / dx * 1e-6;
		dx += 1e-6;
	}
	if (x - 1 < 1e-6)
		result *= -1;
	return result;
}


double lnd(double x)
{
	double df = pow(x, 2.0 + 1e-6) - pow(x, 2.0);
	double dx = 1e-6;
	double f = pow(x, 2.0 + dx / 2);
	return (df / dx) / f;
}

double lnt(double x)
{
	double rx = x;
	for (int i = 1; i <= 20; i++)
		rx = sqrt(rx);
	double df = x * x * rx - x * x;
	double dx = 1 / (double)(1 << 20);
	return (df / dx) / (x * x * sqrt(rx));
}

int main()
{
	float x;
	printf("x = ");
	scanf("%f", &x);
	printf("ln(%f) = %f\n", x, lnt(x));
	printf("ln(%f) = %f\n", x, lnd(x));
	return 0;
}
