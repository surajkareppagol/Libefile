/**************************************/
/* efile.c */
/**************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARACTER_BUFFER_LENGTH 10000
#define MAX_LINE_BUFFER_LENGTH 10000

char *characterBuffer, *initialCharacterAddress;

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

  char character;

  characterBuffer = (char *)malloc(MAX_CHARACTER_BUFFER_LENGTH * sizeof(char));
  initialCharacterAddress = characterBuffer;

  while ((character = fgetc(filePtr)) != EOF)
    *characterBuffer++ = character;

  *characterBuffer++ = '\n';
  *characterBuffer = '\0';

  characterBuffer = NULL;

  return initialCharacterAddress;
}

/**************************************/
/* Print to screen */
/**************************************/

void eprint(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  char character;
  while ((character = fgetc(filePtr)) != EOF)
    printf("%c", character);
  printf("\n");
}

/**************************************/
/* Read a line */
/**************************************/

char *ereadLine(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  char character;

  characterBuffer = (char *)malloc(MAX_CHARACTER_BUFFER_LENGTH * sizeof(char));
  initialCharacterAddress = characterBuffer;

  while ((character = fgetc(filePtr)) != '\n')
    *characterBuffer++ = character;

  *characterBuffer++ = '\n';
  *characterBuffer = '\0';

  characterBuffer = NULL;

  return initialCharacterAddress;
}

/**************************************/
/* EOF */
/**************************************/
