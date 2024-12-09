#include <bits/stdc++.h>

using namespace std;
char ans[1000003];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  string s;
  int n;
  cin >> n;
  cin >> s;
  unordered_map<char, int> m;
  for (int i = 0; i < 26; ++i)
    m['a' + i] = 0;
  for (int i = 0; i < n; ++i) {
    m[s[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    char currc = s[i];
    char minchar = 0;
    int mincnt = 1000000004;
    for (int j = 0; j < 26; ++j) {
      if (m['a' + j] - (currc == ('a' + j)) < mincnt) {
        mincnt = m['a' + j] - (currc == ('a' + j));
        minchar = 'a' + j;
      }
    }
    ans[i] = minchar;
  }
  printf("%s", ans);
  return 0;
}
