#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;

void solve() {
  int n;
  cin >> n;
  ll need = 0;
  for (int i = 1; i <= n - 2; ++i) {
    ll curr = 0;
    cin >> curr;
    need += curr;
  }
  ll lst2, lst1;
  cin >> lst2 >> lst1;
  cout << lst1 - lst2 + need << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {

    solve();
  }
}
