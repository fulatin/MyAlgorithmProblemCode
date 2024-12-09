#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int l = 0;
  int r = n - 1;
  int last = 0;
  int nowtp = 1;
  long long ans = 0;
  while (l <= r) {
    if (nowtp) {
      int val = arr[r--];
      ans += (val - last) * (val - last);
      last = val;
      nowtp = 0;
    } else {
      int val = arr[l++];
      ans += (val - last) * (val - last);
      last = val;
      nowtp = 1;
    }
  }
  cout << ans;
}
