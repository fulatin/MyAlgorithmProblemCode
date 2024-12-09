#include <iostream>
#include <vector>
typedef long long LL;
using namespace std;

LL L, N, M;
LL arr[1000000];

bool check(LL x) {
  LL lst = 1;
  int usedcnt = 0;
  for (int i = 2; i <= N + 2; ++i) {
    if (arr[i] - arr[lst] >= x) {
      // cout << "we at" << arr[i] << endl;
      lst = i;
    } else {
      usedcnt++;
    }
  }
  // cout << "for " << x << " we have used " << usedcnt << endl;
  return usedcnt <= M;
}

int main() {
  cin >> L >> N >> M;
  arr[1] = 0;
  arr[1 + N + 1] = L;
  for (int i = 2; i <= N + 1; ++i) {
    cin >> arr[i];
  }
  LL l = 1, r = L;
  while (r - l > 1) {
    LL mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  if (check(r))
    cout << r << endl;
  else
    cout << l << endl;
  return 0;
}
