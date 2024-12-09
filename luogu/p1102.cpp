#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

long n, c;
vector<long> v;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> c;
  v.resize(n);
  for (long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long cnt = 0;
  for (long i = 0; i < n; ++i) {
    long a = v[i];
    cnt += upper_bound(v.begin(), v.end(), a + c) -
           lower_bound(v.begin(), v.end(), a + c);
  }
  cout << cnt;
}
