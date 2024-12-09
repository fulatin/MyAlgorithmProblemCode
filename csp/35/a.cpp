#include <map>

#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    map<char, int> wdcnt;
    for (int j = 0; j < s.length(); ++j) {
      wdcnt[s[j]]++;
    }
    bool repeat = 0;
    bool hasnum = 0, haschar = 0, hasspecial = 0;
    for (auto e : wdcnt) {
      if (e.second > 2)
        repeat = 1;
      if (e.first >= '0' && e.first <= '9')
        hasnum = 1;
      else if (e.first >= 'a' && e.first <= 'z' ||
               e.first >= 'A' && e.first <= 'Z')
        haschar = 1;
      else
        hasspecial = 1;
    }
    if (!repeat && hasspecial && haschar && hasnum)
      cout << 2 << endl;
    else if (hasnum && haschar && hasspecial)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
}
