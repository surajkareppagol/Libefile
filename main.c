/**************************************/
/* main.c */
/**************************************/

#include "efile.h"

int main()
{
  eopen("testfile.txt", "r");

  char **newBuffer = ereadLines(NULL);
  // for (int i = 0; i < 1; i++)
  printf("%s", newBuffer[0]);

  return 0;
}

/**************************************/
/* EOF */
/**************************************/
