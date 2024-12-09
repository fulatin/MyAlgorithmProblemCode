#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  char curr = 0;
  int cnt = 0;
  for (int i = 0; s[i] != '\0'; ++i) {

    if (curr != s[i]) {
      curr = s[i];
      cnt = 1;
    } else {
      cnt++;
    }
    if (cnt >= 7) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}
