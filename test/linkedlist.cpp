
#include <cstddef>
#include <cstdio>
struct node {
  int data;
  struct node *next;
};

typedef node head;

head *init_head(int data) {
  head *res;
  res = new head;
  res->data = data;
  return res;
}

void append(int data, head *h) {
  node *ta = new node;
  ta->data = data;
  node *t = h;
  while (t->next != NULL) {
    t = t->next;
  }

  t->next = ta;
}

int main() {
  head *h = init_head(10);
  append(2, h);
  printf("%d %d", h->data, h->next->data);
  return 0;
}
