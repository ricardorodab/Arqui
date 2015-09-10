#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  char buff;
  while(buff = *(argv[1] + i++))
    {
      printf("%c\n",buff);
    }
}
