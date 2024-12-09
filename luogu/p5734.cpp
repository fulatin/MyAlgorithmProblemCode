#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q;
char doc[100000];
char buffer[100000], buffer2[100000];

int main() {
  scanf("%d", &q);
  scanf("%s", doc);
  while (q--) {
    int tp;
    scanf("%d", &tp);
    switch (tp) {
    case 1: {
      scanf("%s", buffer);
      strcat(doc, buffer);
      printf("%s\n", doc);
      break;
    }
    case 2: {
      int start, cnt;
      scanf("%d%d", &start, &cnt);
      memset(buffer, 0, sizeof(buffer));
      strncpy(buffer, doc + start, cnt);
      memset(doc, 0, sizeof(doc));
      strcpy(doc, buffer);
      printf("%s\n", doc);
      break;
    }
    case 3: {
      int pos;
      scanf("%d", &pos);
      memset(buffer, 0, sizeof(buffer));
      scanf("%s", buffer);
      int cnt = strlen(buffer);
      memset(buffer2, 0, sizeof(buffer2));
      strcpy(buffer2, doc + pos);
      strcpy(doc + pos, buffer);
      strcpy(doc + pos + cnt, buffer2);
      printf("%s\n", doc);
      break;
    }
    case 4:
      memset(buffer, 0, sizeof(buffer));
      scanf("%s", buffer);
      char *pos = strstr(doc, buffer);
      if (pos == NULL) {
        printf("-1");
      } else {
        printf("%lu\n", pos - doc);
      }
    }
  }
}
