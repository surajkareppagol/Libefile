/**************************************/
/* efile.c */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

/**************************************/
/* Main functions */
/**************************************/

FILE *mainFilePtr;

/**************************************/
/* Open file */
/**************************************/

FILE *eopen(char *fileName, char *fileMode)
{
  mainFilePtr = fopen(fileName, fileMode);
  return mainFilePtr;
}

FILE *eopenr(char *fileName)
{
  mainFilePtr = fopen(fileName, "r");
  return mainFilePtr;
}

FILE *eopenw(char *fileName)
{
  mainFilePtr = fopen(fileName, "w");
  return mainFilePtr;
}

FILE *eopena(char *fileName)
{
  mainFilePtr = fopen(fileName, "a");
  return mainFilePtr;
}

/**************************************/
/* Read from file */
/**************************************/

char *eread(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  return readTillDelimeter(EOF, filePtr, 0);
}

/**************************************/
/* Print to screen */
/**************************************/

void eprint(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  char printCharacter;

  while (1)
  {
    printCharacter = fgetc(filePtr);
    if (printCharacter == EOF)
      break;
    printf("%c", printCharacter);
  }
  printf("\n");
}

/**************************************/
/* Read a line */
/**************************************/

char *ereadLine(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  return readTillDelimeter('\n', filePtr, 0);
}

/**************************************/
/* Read custom number of lines */
/**************************************/

char *ereadCustomLines(FILE *filePtr, int lines)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  return readTillDelimeter('\0', filePtr, lines);
}

/**************************************/
/* Write to file */
/**************************************/

int ewrite(FILE *filePtr, char *data)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  for (int i = 0; *data != '\0'; i++)
    fputc(*data++, filePtr);

  return 1;
}

/**************************************/
/* EOF */
/**************************************/
