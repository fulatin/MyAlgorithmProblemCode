#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void sol() {
  vector<int> s;
  for (int i = 1; i <= 3; ++i) {
    int curr;
    cin >> curr;
    s.push_back(curr);
  }
  sort(s.begin(), s.end());
  cout << s[2] - s[0] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    sol();
  return 0;
}
