#include <stdio.h>
#include <stdlib.h>

struct stu {
  int id;
  int a;
  int b;
  bool isexce() {
    return (this->a * 7 + this->b * 3 >= 800) && (this->a + this->b) >= 140
               ? true
               : false;
  }
} stus[1003];

int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &(stus[i].id), &(stus[i].a), &(stus[i].b));
    if (stus[i].isexce()) {
      printf("Excellent\n");
    } else {
      printf("Not excellent\n");
    }
  }
}
