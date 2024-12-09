
#include <iostream>
using namespace std;

void ca() {
  int n;
  cin >> n;
  if (n >= 3) {
    cout << "NO" << endl;
    int l;
    for (int i = 1; i <= n; ++i) {
      cin >> l;
    }
    return;
  }
  int a, b;
  cin >> a >> b;
  if (abs(a - b) > 1) {
    cout << "YES" << endl;

  } else {
    cout << "NO" << endl;
  }
}
int main() {
  int cases;
  std::cin >> cases;
  while (cases--) {
    ca();
  }
  return 0;
}
