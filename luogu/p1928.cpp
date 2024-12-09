#include <bits/stdc++.h>
#include <cctype>

using namespace std;

string resolve(string s, int mult) {
  string tmpres;
  int i = 0;
  while (i < s.size()) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      tmpres += s[i];
    } else if (s[i] == '[') {
      int start = i + 1;
      int factor = 0;
      while (isdigit(s[start]))
        factor = factor * 10 + s[start++] - '0';
      string passnext;
      int st = start;
      // start = i + 1;
      int depth = 1;
      while (depth != 0) {
        if (s[start] == '[')
          depth += 1;
        if (s[start] == ']')
          depth -= 1;
        start++;
      }
      start--;
      for (int j = st; j < start; ++j) {
        passnext += s[j];
      }
      tmpres += resolve(passnext, factor);
      i = start;
    }
    i++;
  }
  string final;
  for (int i = 1; i <= mult; ++i) {
    final += tmpres;
  }
  return final;
}

int main() {
  string s;
  cin >> s;
  cout << resolve(s, 1) << endl;
  return 0;
}
