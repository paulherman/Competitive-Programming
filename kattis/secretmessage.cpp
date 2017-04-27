#include <iostream>
using namespace std;

int main() {
  int numMessages = 0;
  cin >> numMessages;

  char encryption[10000] = { 0 };
  for (int messageId = 0; messageId < numMessages; messageId++) {
    string message;
    cin >> message;

    int sqrtLength = 0;
    for (; sqrtLength * sqrtLength < message.length(); sqrtLength++);

    for (int i = 0; i < sqrtLength; i++) {
      for (int j = 0; j < sqrtLength; j++) {
        int index = i * sqrtLength + j;
        encryption[index] = index < message.length() ? message[index] : '*';
      }
    }

    int decIndex = 0;
    for (int i = 0; i < sqrtLength; i++) {
      for (int j = 0; j < sqrtLength; j++) {
        int encIndex = (sqrtLength - 1 - j) * sqrtLength + i;
        if (encryption[encIndex] != '*') {
          message[decIndex] = encryption[encIndex];
          decIndex++;
        }
      }
    }
    cout << message << "\n";
  }

  return 0;
}
