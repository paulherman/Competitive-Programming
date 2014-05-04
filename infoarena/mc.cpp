#include <cstdlib>
#include <ctime>
#include <cstdio>

float rd()
{
	return (float)rand() / (float)RAND_MAX;
}
float f(float x)
{
	return x * x;
}
int main()
{
	float a, b;
	int n = 100000000;
	int count = 0;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		float x = rd();
		float y = rd();
		if (x * x + y * y < 1)
			count++;
	}
	printf("%f\n", (float)count / (float)n * 4.0);
	return 0;
}
