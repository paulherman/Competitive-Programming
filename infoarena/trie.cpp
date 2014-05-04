#include <cstdio>
#include <cstring>

struct trie
{
	trie *fii[26];
	int count;
	int nrFii;
};

int ctoi(char c)
{
	return c - 'a';
}

void insert(trie *t, char *w)
{
	if (*w == 0)
		t->count++;
	else
	{
		if (t->fii[ctoi(*w)] == NULL)
		{
			t->fii[ctoi(*w)] = new trie;
			t->nrFii++;
		}
		insert(t->fii[ctoi(*w)], w + 1);
	}
}
bool remove(trie *nod, char *w)
{
	if (*w == 0)
		nod->count--;
	else if (remove(nod->fii[ctoi(*w)], w + 1) == true)
	{
		nod->fii[ctoi(*w)] = NULL;
		nod->nrFii--;
	}
	if ((nod->count == 0) && (nod->nrFii == 0) && (nod != t))
	{
		delete nod;
		return true;
	}
	return false;
}
int prefix(trie *nod, char *w, int len)
{
	if ((*w == 0) || (nod->fii[ctoi(*w)] == NULL)
		return len;
	return prefix(nod->fii[ctoi(*w)], w + 1, len);
}
int search(trie *nod, char *w)
{
	if (*w == 0)
		return nod->count;
	if (nod->fii[ctoi(*w)] != NULL)
		return search(nod->fii[ctoi(*w)], w + 1);
	return 0;
}

int main()
{
	char w[255];
	int q;
	freopen("trie.in", "r", stdin);
	//freopen("trie.out", "w", stdout);
	while (feof(stdin) == false)
	{
		memset(w, 0, sizeof(w));
		scanf("%d %s", &q, w);
		switch (q)
		{
			case 0:
				insert(t, w);
				break;
			case 1:
				remove(t, w);
				break;
			case 2:
				printf("%d\n", search(t, w));
				break;
			case 3:
				printf("%d\n", prefix(t, w));
				break;
		}
	}
	return 0;
}
