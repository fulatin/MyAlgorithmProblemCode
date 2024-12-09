#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, char> mp;
map<char, int> loop;
int main() {
  string s;
  getline(cin, s);
  int n;
  cin >> n;
  getchar();
  for (int i = 0; i < 26; ++i) {
    mp['a' + i] = 'a' + i;
    mp['A' + i] = 'A' + i;
  }
  for (int i = 0; i < 9; ++i) {
    mp['0' + i] = '0' + i;
  }
  mp['#'] = '#';
  mp[' '] = ' ';
  for (int i = 0; i < n; ++i) {
    string tmps;
    getline(cin, tmps);

    mp[tmps[1]] = tmps[2];
  }
  for (auto e : mp) {
    int mod = 0;
    map<char, int> modcnt;
    char ch = e.first;
    while (mod <= 70 && modcnt[mp[ch]] == 0) {
      ch = mp[ch];
      modcnt[ch] = ++mod;
    }
    loop[mp[ch]] = mod - modcnt[mp[ch]] + 1;
  }
  // for (auto e : loop) {
  //   cout << e.first << ' ' << e.second << endl;
  // }
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    string scp = s;
    for (int i = 0; i < s.length(); ++i) {
      char ch = s[i];
      long long cpk = k;
      while (cpk > 0) {
        if (loop[ch] == 1) {
          cpk = 0;
        } else if (loop[ch] == 0) {
          ch = mp[ch];
          cpk--;
        } else {
          cpk %= loop[ch];
          if (cpk == 0)
            continue;
          ch = mp[ch];
          cpk--;
        }
      }
      cout << ch;
    }
    cout << endl;
  }
}
