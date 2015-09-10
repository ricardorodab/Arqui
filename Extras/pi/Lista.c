#include <stdio.h>

typedef struct li{
  char head;
  struct li *tail; } Lista;

Lista n = {'a', NULL};
Lista m = {'b', &n};
int main(void)
{
  return 0;
}
