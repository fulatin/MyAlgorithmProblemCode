#include <iostream>

using namespace std;

int cases, n, cnt[103];

void cs() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int curr;
    cin >> curr;
    cnt[curr]++;
  }
  int max = -1;
  int val = -1;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > val) {
      max = i;
      val = cnt[i];
    }
  }
  cout << (n - val) << endl;
}

int main() {
  cin >> cases;
  while (cases--) {
    cs();
  }
}
