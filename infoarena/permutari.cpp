/*
 * Autor: Paul Herman
 * Problema: generare permutari
 * Data: 17.01.2012
 * Punctaj: 100
 * Link: http://www.infoarena.ro/problema/permutari
 */
#include <fstream>
using namespace std;

ofstream fout;
short int n;
int permutare[9];

inline void scriere()
{
	for (int i = 0; i < n; i++)
		printf("%d ", permutare[i]);
	printf("\n");
}
inline bool verificare(int k, int v)
{
	for (int i = 0; i < k; i++)
		if (permutare[i] == v)
			return false;
	return true;
}
void backtracking(int k)
{
	if (k == n)
		scriere();
	else
	{
		//Parcurgem toate valorile posibile
		for (int i = 1; i <= n; i++) {
			if (verificare(k, i) == true) {
				permutare[k] = i;
				backtracking(k + 1);
			}
		}
	}
}
int main()
{
	freopen("permutari.in", "r", stdin);
	freopen("permutari.out", "w", stdout);

	scanf("%d", &n);

	backtracking(0);

	return 0;
}

