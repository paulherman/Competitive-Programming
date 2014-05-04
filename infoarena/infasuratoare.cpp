#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, pi;
double x[120001], y[120001];
vector<int> puncte;
int stack[120001], stack_size;

inline void stack_push(int x)
{
	stack_size++;
	stack[stack_size] = x;
}
double arie2(int i1, int i2, int i3)
{
	return (long double)x[i1] * y[i2] + x[i2] * y[i3] + x[i3] * y[i1] - y[i1] * x[i2] - y[i2] * x[i3] - y[i3] * x[i1];
}
bool unghi(int i, int j)
{
	return (double)(x[i] - x[pi]) * (y[j] - y[pi]) < (double)(x[j] - x[pi]) * (y[i] - y[pi]);
}
int main()
{
	freopen("infasuratoare.in", "r", stdin);
	freopen("infasuratoare.out", "w", stdout);
	scanf("%d", &n);
	pi = 0;
	x[0] = 1000000001;
	y[0] = 1000000001;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		if ((x[i] < x[pi]) || ((x[i] == x[pi]) && (y[i] < y[pi])))
			pi = i;
	}
	for (int i = 1; i <= n; i++)
		if (i != pi)
			puncte.push_back(i);
	sort(puncte.begin(), puncte.end(), unghi);
	stack_push(pi);
	for (int i = 0; i < puncte.size(); i++)
	{
		while ((stack_size >= 2) && (arie2(stack[stack_size - 1], stack[stack_size], puncte[i]) > 0))
			stack_size--;
		stack_push(puncte[i]);
	}
	printf("%d\n", stack_size);
	for (int i = stack_size; i > 0; i--)
		printf("%lf %lf\n", x[stack[i]], y[stack[i]]);
}
