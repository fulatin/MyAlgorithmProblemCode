#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n, s;
int a, b;

vector<int> can;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  cin >> a >> b;
  for (int i = 1; i <= n; ++i) {
    int h, strength;
    cin >> h >> strength;
    if (h <= a + b)
      can.push_back(strength);
  }
  sort(can.begin(), can.end());
  int cnt = 0;
  for (int e : can) {
    if (s >= e) {
      cnt++;
      s -= e;
    }
  }
  printf("%d", cnt);
}
