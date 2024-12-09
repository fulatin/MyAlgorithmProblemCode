#include <iostream>

using namespace std;

int cases, arr[2 * (int)10e5 + 3];

void cs() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1 << endl;
    return;
  }
  int mid = (n + 1) / 2;

  for (int i = mid; i >= 1; i--) {
    arr[i] = (mid - i) * 2;
  }
  for (int i = mid; i <= n; ++i) {
    arr[i] = (i - mid + 1) * 2 - 1;
  }
  for (int i = 1; i <= n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main() {
  cin >> cases;
  while (cases--) {
    cs();
  }
}
