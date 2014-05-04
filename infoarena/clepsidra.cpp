#include <cstdio>

int stare[1001], n;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

//Nivelul de pe care pornesc boabele, nivelul pe care ajung boabele, secunde
int transformareJos(int l, int k, int s)
{
	int b = stare[l];
	//printf("tj(%d %d %d %d) = ", l, k, s, b);
	if ((l == 0) && (k == 0)) //De pe nivelul inferior boabele nu coboara
		return b;
	if (l == k) //Boabe ramase in recipientul initial
		return max(0, b - s);
	if (k == 0) //Boabe adunate in recipientul inferior
		return max(0, min(b, s - (l - k) + 1));
	if (s < l - k) //Timpul este mai mic decat timpul necesar sa ajunga o boaba in recipient
		return 0;
	if (s >= b + l - k) //Boabele au trecut deja prin recipient
		return 0;
	return 1; //O boaba se afla in tranzitie prin recipient
}

//Nivelul de pe care pornesc boabele, nivelul pe care ajung boabele, secunde
int transformareSus(int l, int k, int s)
{
	int b = stare[l];
	//printf("ts(%d %d %d %d) = ", l, k, s, b);
	if ((l == n) && (k == n)) //Boabele nu urca
		return b;
	if (l == k) //Boabe ramase in recipientul initial
		return max(0, b - s);
	if (k == n) //Boabe adunate in recipientul superior
		return max(0, min(b, s - (k - l) + 1));
	if (s < (k - l)) //Timpul este mai mic decat timpul necesar sa ajunga o boaba in recipient
		return 0;
	if (s >= b + (k - l)) //Boabele au trecut deja prin recipient
		return 0;
	return 1; //O boaba se afla in tranzitie prin recipient
}

void updateStare(int secunde, int pozitie)
{
	int stareNoua[1001] = {0};
	if (pozitie == 1)
	{
		for (int i = 0; i <= n; i++)
			if (stare[i] > 0)
				for (int j = 0; j <= i; j++)
					stareNoua[j] += transformareJos(i, j, secunde);
	}
	else
	{
		for (int i = 0; i <= n; i++)
			if (stare[i] > 0)
				for (int j = i; j <= n; j++)
					stareNoua[j] += transformareSus(i, j, secunde);
	}
	for (int i = 0; i <= n; i++)
		stare[i] = stareNoua[i];
}

int main()
{
	//printf("t(ni, nf, s, b)\n");
	freopen("clepsidru.in", "r", stdin);
	//freopen("clepsidru.out", "w", stdout);
	int b, k, secunde, pozitie;
	scanf("%d %d\n", &n, &b);
	scanf("%d\n", &k);
	stare[n] = b;
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &secunde, &pozitie);
		updateStare(secunde, pozitie);
	}
	printf("%d\n", n + b - 1);
	if (pozitie == 1)
	{
		for (int i = n; i >= 2; i--)
			printf("%d %d\n", stare[i], 0);
		printf("%d %d\n", stare[1], stare[0]);
	}
	else
	{
		printf("%d %d\n", stare[n], stare[n - 1]);
		for (int i = n - 2; i >= 0; i--)
			printf("%d %d\n", 0, stare[i]);
	}
	return 0;
}
