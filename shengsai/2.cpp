#include <bits/stdc++.h>

using namespace std;
int main() {
  double a = 0.0;
  scanf("%lf", &a);
  long b = a * 100.0;
  int rd = 1;
  if (a <= 0.00001) {
    printf("%d", 1);
    return 0;
  }
  while (1) {
    for (int i = 1; i <= rd; ++i) {
      if ((int)round(((double)i) / rd * 10000.0) == b)
        goto out;
    }
    rd++;
  }
out:
  cout << rd;
}
