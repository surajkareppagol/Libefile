/**************************************/
/* main.c */
/**************************************/

#include "efile.h"

int main()
{
  eopen("testfile.txt", "r");

  char *newBuffer = eread(NULL);
  printf("%s", newBuffer);

  return 0;
}

/**************************************/
/* EOF */
/**************************************/
