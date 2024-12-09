#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 5 * 1e4 + 3;

int N, M;
LL L;
vector<LL> arr;

bool check(LL x) {
  // printf("now is %lld", x);
  int rmcnt = 0;
  int last = 0;
  for (int i = 1; i < N + 2; ++i) {
    if (arr[i] - arr[last] < x) {
      rmcnt++;
      // printf("removed %lld\n", arr[i]);
    } else {
      last = i;
    }
  }
  return rmcnt <= M;
}

int main() {
  cin >> L >> N >> M;
  arr.resize(N + 2);
  arr[0] = 0;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i + 1];
  }
  arr[N + 1] = L;
  sort(arr.begin(), arr.end());
  LL l = 0, r = L;
  while (r - l > 1) {
    LL mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << (check(r) ? r : l) << endl;
}
