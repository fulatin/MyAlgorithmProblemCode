// #include <bits/stdc++.h>
// #include <queue>
//
// using namespace std;
// const int MAXN = 1e6 + 2;
// typedef long long LL;
// LL mxroom[MAXN];
// struct resv {
//   int id;
//   int sd;
//   int ed;
//   LL rm;
// };
// int n, m;
//
// bool cmp1(struct resv a, struct resv b) { return a.sd < b.sd; }
// struct cmp2 {
//   bool operator()(struct resv a, struct resv b) { return a.ed < b.ed; };
// };
// int main() {
//   cin >> n >> m;
//   for (int i = 1; i <= n; ++i) {
//     cin >> mxroom[i];
//   }
//   vector<struct resv> arr1(m);
//   for (int i = 0; i < m; ++i) {
//     cin >> arr1[i].rm;
//     arr1[i].id = i + 1;
//     cin >> arr1[i].sd;
//     cin >> arr1[i].ed;
//   }
//   sort(arr1.begin(), arr1.end(), cmp1);
//   for (int i = 0; i < m; ++i) {
//     cout << arr1[i].sd << ' ';
//   }
//   priority_queue<struct resv, vector<resv>, cmp2> a;
//   stack<struct resv> a2;
//   set<int> deled;
//   vector<int> calldel;
//   LL nowresved = 0;
//   int nowat = 0;
//   for (int i = 1; i <= n; ++i) {
//     if (!a.empty()) {
//       while (!a.empty() && ((a.top().ed + 1) == i)) {
//         if (deled.find(a.top().id) != deled.end()) {
//           a.pop();
//         } else {
//           printf("we reach the end of %d \n", a.top().id);
//           nowresved += a.top().rm;
//           deled.insert(a.top().id);
//           a.pop();
//         }
//       }
//     }
//     while (arr1[nowat].sd == i) {
//       nowresved += arr1[nowat].rm;
//       a.push(arr1[nowat]);
//       a2.push(arr1[nowat]);
//       nowat++;
//     }
//     while (!a2.empty() && nowresved > mxroom[i]) {
//       printf("today is %d", i);
//       printf("resroom is %lld, so we del %d\n", nowresved, a.top().id);
//       if (deled.find(a2.top().id) == deled.end()) {
//         deled.insert(a2.top().id);
//         calldel.push_back(a2.top().id);
//         nowresved -= a2.top().rm;
//       }
//       a2.pop();
//     }
//   }
//   if (!calldel.empty()) {
//     cout << -1 << endl;
//     for (auto e : calldel)
//       cout << e << endl;
//   } else {
//     cout << 0;
//   }
//   return 0;
// }
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
const int MAXN = 1e6 + 3;
typedef long long LL;
int n, m;
LL mx[MAXN];
LL d[MAXN];
int s[MAXN], e[MAXN];
LL diff[MAXN];

bool check(int x) {
  // cout << "now check " << x << endl;
  memset(diff, 0, n * sizeof(LL));
  for (int i = 1; i <= x; ++i) {
    diff[s[i]] += d[i];
    diff[e[i] + 1] -= d[i];
  }
  LL sm = 0;
  for (int i = 1; i <= n; ++i) {
    sm += diff[i];
    if (sm > mx[i])
      return false;
  }
  return true;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> mx[i];
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%d%d", d + i, s + i, e + i);
  }
  int l = 0, r = m + 1;
  if (check(m)) {
    cout << 0 << endl;
    return 0;
  }
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << -1 << endl << r;
  return 0;
}
