#include <cstdio>
#include <iostream>
using namespace std;

char s[30];
int main() {
  int d;
  cin >> d;
  while (d--) {
    for (int i = 0; i < 30; i++) {
      s[i] = 0;
    }
    cin >> s;
    if (s[0] == '1' && s[1] == '0' && s[2] != '0') {
      int pow = 0;
      for (int j = 2; j <= 29; ++j) {
        if (s[j] == '\0')
          break;
        int curr = s[j] - '0';
        pow = pow * 10 + curr;
      }
      if (pow >= 2) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
