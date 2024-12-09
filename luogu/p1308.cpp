#include <bits/stdc++.h>
#include <cctype>

using namespace std;

const int MAXN = (int)10e6;

long idx;
long pos[MAXN + 1], cnt[MAXN + 1];
void s2l(string &s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }

int main() {
  map<string, int> m;
  string target;
  cin >> target;
  s2l(target);
  while (true) {
    string curr;
    cin >> curr;
    if (curr.empty()) {
      break;
    }
    s2l(curr);
    if (m.find(curr) != m.end()) {
      cnt[m.find(curr)->second]++;
    } else {
      pos[idx] = idx;
      cnt[idx]++;
      m.insert({curr, idx++});
    }
  }
  if (m.find(target) == m.end()) {
    cout << -1;
  } else {
    auto res = m.find(target)->second;
    cout << cnt[res] << ' ' << pos[res];
  }
}
