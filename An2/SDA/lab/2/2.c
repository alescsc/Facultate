#include <stdio.h>

int main(void)
  {
      int n;
      printf("n="); scanf("%d", &n);
      int i = 1, a = 0, b = 1, s = 1;
      while (i != n) {
          s = a + b;
          a = b;
          b = s;
          i++;
      }

      printf("%d\n", s);
  }