/**************************************/
/* main.c */
/**************************************/

#include "efile.h"

int main()
{
  FILE *filePtr = eopen("testfile.txt", "r");

  char *buffer;

  printf("------------------\n");
  printf("| From \"eread()\" |\n");
  printf("------------------\n");
  buffer = eread(NULL);
  printf("%s", buffer);

  fseek(filePtr, 0, SEEK_SET);

  printf("\n\n-------------------\n");
  printf("| From \"eprint()\" |\n");
  printf("-------------------\n");
  eprint(NULL);

  fseek(filePtr, 0, SEEK_SET);

  printf("\n\n----------------------\n");
  printf("| From \"ereadLine()\" |\n");
  printf("----------------------\n");
  buffer = ereadLine(NULL);
  printf("%s", buffer);

  fseek(filePtr, 0, SEEK_SET);

  printf("\n\n-----------------------------\n");
  printf("| From \"ereadCustomLines()\" |\n");
  printf("-----------------------------\n");
  buffer = ereadCustomLines(NULL, 6);
  printf("%s", buffer);

  fseek(filePtr, 0, SEEK_SET);

  eFreeBuffer(buffer);

  return 0;
}

/**************************************/
/* EOF */
/**************************************/
