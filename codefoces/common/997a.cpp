#include <iostream>

using namespace std;
int num, k;
int main() {
  cin >> num >> k;
  while (k--) {
    if ((num % 10) != 0) {
      num -= 1;
    } else {
      num /= 10;
    }
  }
  cout << num;
  return 0;
}
