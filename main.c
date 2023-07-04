/**************************************/
/* main.c */
/**************************************/

#include "efile.h"

int main()
{
  eopen("testfile.txt", "r");

  char *buffer = ereadLine(NULL);
  printf("%s", buffer);

  return 0;
}

/**************************************/
/* EOF */
/**************************************/
