#include <iostream>

using namespace std;

char tmp[60];
int main() {
  string s;
  int n, sec;
  cin >> n >> sec;
  cin >> s;
  while (sec--) {
    for (int i = 0; i < n; i++) {
      if (i <= n - 2 && s[i] == 'B' && s[i + 1] == 'G') {
        tmp[i] = 'G';
        tmp[i + 1] = 'B';
        i++;
      } else {
        tmp[i] = s[i];
      }
    }
    for (int i = 0; i < n; ++i) {
      s[i] = tmp[i];
    }
  }
  cout << s;
  return 0;
}
