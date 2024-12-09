#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    map<int, int> mdcnt;
    map<int, int> mdpos;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
      mdcnt[arr[i] % k]++;
      mdpos[arr[i] % k] = i;
    }
    int has = 0;
    for (auto e : mdcnt) {
      if (e.second == 1) {
        has = 1;
        cout << "Yes\n" << mdpos[e.first] << endl;
        break;
      }
    }
    if (!has)
      cout << "No" << endl;
  }
}
