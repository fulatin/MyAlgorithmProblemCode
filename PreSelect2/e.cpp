
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int arr[102];
int main() {
  int m, s;
  cin >> m >> s;
  if (s == 0 && m != 1) {
    cout << "-1 -1";
    return 0;
  }
  arr[1] = 1;
  int cps = s;

  cps--;
  for (int i = m; i >= 2; i--) {
    if (cps <= 9) {
      arr[i] = cps;
      cps = 0;
      break;
    } else {
      arr[i] = 9;
      cps -= 9;
    }
  }
  if (arr[1] + cps > 9) {
    cout << -1 << ' ';
  } else {
    arr[1] += cps;
    for (int i = 1; i <= m; ++i) {
      cout << arr[i];
    }
    cout << ' ';
  }

  cps = s;
  memset(arr, 0, sizeof(arr));
  for (int i = 1; i <= m; ++i) {
    if (cps <= 9) {
      arr[i] = cps;
      cps = 0;
    } else {
      arr[i] = 9;
      cps -= 9;
    }
  }
  if (cps != 0) {
    cout << -1;
  } else {
    for (int i = 1; i <= m; ++i) {
      cout << arr[i];
    }
  }
  return 0;
}
