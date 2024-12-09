#include <cstdlib>
#include <iostream>

using namespace std;

int t;
int arr[200003];

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  qsort(arr + 1, n, sizeof(int), cmp);
  cout << arr[(n / 2) + 1] << endl;
}

int main() {
  cin >> t;

  while (t--) {
    solve();
  }
}
