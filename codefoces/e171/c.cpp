#include <bits/stdc++.h>

using namespace std;

int t;
int n;
string s;

void solve() {
  cin >> n;
  cin >> s;
  unsigned long long money = ((1 + n) * n) >> 1;
  stack<int> delable;
  delable.push(0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      delable.push(i + 1);
  }
  int used = 0;

  while (used + 1 < delable.top() && delable.size() >= 2) {
    int a, b;
    a = delable.top();
    delable.pop();
    b = delable.top();
    used++;
    used -= a - b - 1;
    if (used < 0)
      used = 0;
    money -= a;
  }
  cout << money << endl;
}

int main() {
  cin >> t;
  while (t--)
    solve();
  return 0;
}
