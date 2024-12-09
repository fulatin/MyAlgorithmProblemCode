#include <cstdlib>
#include <iostream>
using namespace std;

int arr[2 * (int)10e5 + 3];
int diff[2 * (int)10e5 + 3];
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
void cs() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  qsort(arr + 1, n, sizeof(int), cmp);
  for (int i = 1; i <= (int)n / 2; ++i) {
    diff[i] = arr[2 * i - 1] - arr[2 * i];
  }
  int sum = 0;
  for (int i = 1; i <= n / 2; ++i) {
    sum += diff[i];
  }
  if (n % 2) {
    sum = sum - k;
    if (sum <= 0) {
      cout << arr[n] << endl;
    } else {
      cout << (sum + arr[n]) << endl;
    }
  } else {
    cout << (sum <= k ? 0 : sum - k) << endl;
  }
}
int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    cs();
  }
  return 0;
}
