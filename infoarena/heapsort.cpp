/*
 * Autor: Paul Herman
 * Problema: sortare cu heap-uri
 * Data: 01.10.2011
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/algsort
 */
#include <cstdio>

int v[500000], n;

void swap(int *v, int a, int b)
{
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}
void heapDown(int *v, int pos, int size)
{
	int left = 2 * pos + 1;
	int right = left + 1;
	int largest = pos;
	if ((left < size) && (v[left] > v[largest]))
		largest = left;
	if ((right < size) && (v[right] > v[largest]))
		largest = right;
	if(largest != pos)
	{
		swap(v, pos, largest);
		heapDown(v, largest, size);
	}
}
void heapsort(int *v, int size)
{
	for (int i = n / 2; i >= 0; i--)
		heapDown(v, i, size);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(v, 0, i);
		size--;
		heapDown(v, 0, size);
	}
}

int main()
{
	freopen("algsort.in", "r", stdin);
	freopen("algsort.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	heapsort(v, n);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	return 0;
}
