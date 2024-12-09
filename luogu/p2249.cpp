#include <bits/stdc++.h>
#include <ios>

using namespace std;

int arr[(int)10e6 + 2];
int n, m;
void f(int q) {
  int l = 1;
  int r = n;

  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (arr[mid] > q) {
      r = mid;
    } else if (arr[mid] < q) {
      l = mid;
    } else if (arr[mid] == q) {
      r = mid;
    }
  }
  if (l == r) {
    if (arr[l] == q) {
      cout << l << ' ';
    } else {
      cout << -1 << ' ';
    }
  } else {
    if (arr[l] == q) {
      cout << l << ' ';

    } else if (arr[r] == q) {
      cout << r << ' ';
    } else {
      cout << -1 << ' ';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  while (m--) {
    int q;
    cin >> q;
    f(q);
  }
}
