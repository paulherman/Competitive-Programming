#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  bool done = false;
  while (!done) {
    int keyLength = 0;
    cin >> keyLength;

    if (keyLength == 0) {
      done = true;
    } else {
      vector<int> key(keyLength);
      for (int i = 0; i < keyLength; i++)
        cin >> key[i];
      cin.ignore();

      string message;
      getline(cin, message);

      int encryptedLength = keyLength * (message.length() / keyLength + (message.length() % keyLength > 0));
      string encrypted(encryptedLength, ' ');
      for (int i = 0; i < encryptedLength; i++) {
        int index = i - i % keyLength + key[i % keyLength] - 1;
        encrypted[i] = index < message.length() ? message[index] : ' ';
      }
      cout << "'" << encrypted << "'\n";
    }
  }
  return 0;
}
