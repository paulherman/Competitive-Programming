#include <iostream>
#include <string>
using namespace std;

class Trie {
public:
	Trie() {
		word = false;
		for (int i = 0; i < 3; i++)
			children[i] = NULL;
	}
	void add(const string &str) {
		Trie *node = this;
		for (int pos = 0; pos < str.length(); pos++) {
			int c = toIndex(str[pos]);
			if (node->children[c] == NULL)
				node->children[c] = new Trie();
			node = node->children[c];
		}
		node->word = true;
	}

	bool query(const string &str, int pos, int diff) {
		if (pos == str.length())
			return word && diff == 1;

		int c = toIndex(str[pos]);
		for (int i = 0; i < 3; i++) {
			Trie *next = children[i];
			int nextDiff = i == c ? diff : diff + 1;
			if (next != NULL && nextDiff <= 1 && next->query(str, pos + 1, nextDiff))
				return true;
		}

		return false;
	}
private:
	bool word;
	Trie *children[3];
	int toIndex(char c) {
		return c - 'a';
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Trie dictionary;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		dictionary.add(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (dictionary.query(s, 0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}