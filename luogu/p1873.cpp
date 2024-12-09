#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

typedef long long ull;

const int MAXN = 1000000;
const ull MAXM = 1000000000 * 2;
int n, arr[MAXN + 2];
ull m;
ull parr[MAXN + 2];

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  qsort(arr + 1, n, sizeof(int), cmp);
  for (int i = 1; i <= n; ++i) {
    parr[i] = parr[i - 1] + i * (arr[i] - arr[i + 1]);
    if (parr[i] >= m) {
      ull x = (m - parr[i - 1] + i - 1) / i;
      cout << arr[i] - x;
      return 0;
    }
  }
}
