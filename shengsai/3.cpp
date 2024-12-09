#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
struct dt {
  int a;
  int b;
  bool dead;
  bool operator<(dt o) { return o.b < this->b; }
};
int main() {
  int n;
  cin >> n;
  vector<dt> arr(n);
  LL maxa = -1;
  for (int i = 0; i < n; ++i) {
    LL ca, cb;
    cin >> ca >> cb;
    maxa = max(ca, maxa);
    arr[i].a = ca;
    arr[i].b = cb;
    arr[i].dead = false;
  }

  sort(arr.begin(), arr.end());
  for (auto e : arr) {
    cout << e.b;
  }
  LL dmg = 0;
  int cnt = 0;
  for (int i = 0; i < n || dmg < maxa; ++i) {
    if (arr[i].dead)
      continue;
    cnt++;
    arr[i].dead = true;
    dmg += arr[i].b;
  start:
    for (int j = i; j < n; ++j) {
      if (arr[j].dead)
        continue;
      if (dmg >= arr[j].a) {
        dmg += arr[j].b;
        arr[j].dead = true;
        goto start;
      }
    }
  }
  cout << cnt;
  return 0;
}
