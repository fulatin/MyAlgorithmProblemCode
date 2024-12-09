#include <iostream>

using namespace std;

int n, b, d;

int main() {
  cin >> n >> b >> d;

  int wst = 0, cleanc = 0;
  while (n--) {
    int curr;
    cin >> curr;
    if (curr > b)
      continue;
    wst += curr;
    if (wst > d) {
      wst = 0;
      cleanc++;
    }
  }
  cout << cleanc;
  return 0;
}
