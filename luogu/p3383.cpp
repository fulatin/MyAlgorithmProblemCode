#include <bits/stdc++.h>
#include <cstring>

using namespace std;

const int N = (int)10e8;
bitset<N + 2> isprime;
int prime[6000010];
int cnt;
int n, q;

int main() {
  scanf("%d%d", &n, &q);
  isprime.set();
  for (int i = 2; i <= n; ++i) {
    if (isprime[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
      isprime[i * prime[j]] = false;
      if (prime[j] % i == 0)
        break;
    }
  }
  while (q--) {
    int curr;
    scanf("%d", &curr);
    printf("%d\n", prime[curr]);
  }
}
