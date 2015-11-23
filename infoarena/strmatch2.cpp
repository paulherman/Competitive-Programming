#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int mod = 17;
const int rem = 100007;

int hashStr(const string &str, size_t length) {
    int value = 0;
    int exp = 1;
    for (size_t i = 0; i < length; i++) {
        value = (value + exp * str[i]) % rem;
        exp = (exp * mod) % rem;
    }
    return value;
}

vector<size_t> match(const string &pat, const string &str) {
    vector<size_t> matches;

    int patHash = hashStr(pat, pat.length());
    int strHash = hashStr(str, pat.length());
    int exp = pow(mod, pat.length() - 1);

    for (size_t i = 0; i < str.length() - pat.length() + 1; i++) {
        cout << i << " " << patHash << " " << strHash << endl;
        if (patHash == strHash) {
            bool strmatch = true;
            cout << "possible match at " << i << endl;

            for (size_t j = 0; j < pat.length(); j++)
                if (pat[j] != str[i + j])
                    strmatch = false;

            if (strmatch)
                matches.push_back(i);
        }

        if (i + pat.length() < str.length())
            strHash = (mod * (strHash - str[i] * exp) % rem + str[i + pat.length()]) % rem;
    }

    return matches;
}

int main() {
    string pattern, str;
    cin >> pattern >> str;

    vector<size_t> matches = match(pattern, str);

    cout << matches.size() << endl;
    for (size_t m : matches)
        cout << m << " ";

    return 0;
}
