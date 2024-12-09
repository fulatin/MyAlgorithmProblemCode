#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, ave = 0;

  cin >> n;
  vector<int> arr(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    ave += arr[i];
  }
  ave /= n;
  vector<int> lsum(n + 1);
  vector<int> rsum(n + 2);
  for (int i = 1; i <= n; ++i) {
    lsum[i] = arr[i] + lsum[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    rsum[i] = arr[i] + rsum[i + 1];
  }
  int ans = (arr[1] > ave ? 1 : 0) + (arr[n] > ave ? 1 : 0);
  for (int i = 2; i <= n - 1; ++i) {
    ans += (lsum[i - 1] < ave * (i - 1) ? 1 : 0) +
           (rsum[i + 1] < ave * (n - i) ? 1 : 0);
  }
  cout << ans;
}
