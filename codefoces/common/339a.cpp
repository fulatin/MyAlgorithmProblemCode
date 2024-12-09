#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

struct compare {
  bool operator()(int a, int b) { return a > b; }
};

std::priority_queue<int, std::vector<int>, compare> q;
int main() {
  char c;

  while ((c = getchar()) != '\n') {
    if (c == '1') {
      q.push(1);
    } else if (c == '2') {
      q.push(2);
    } else if (c == '3') {
      q.push(3);
    }
  }
  printf("%d", q.top());
  q.pop();
  while (!q.empty()) {
    printf("+%d", q.top());
    q.pop();
  }
}
