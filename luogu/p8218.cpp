#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100003;
int arr[MAXN], n, m;
int sum[MAXN];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + arr[i];
  }
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << sum[b] - sum[a - 1] << endl;
  }
  return 0;
}
