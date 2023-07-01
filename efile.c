/**************************************/
/* efile.c */
/**************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARACTER_BUFFER_LENGTH 10000
#define MAX_LINE_BUFFER_LENGTH 10000

char *characterBuffer, *intialCharacterAddress;
char **lineBuffer, **intialLineAddress;

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
  intialCharacterAddress = characterBuffer;

  while ((character = fgetc(filePtr)) != EOF)
    *characterBuffer++ = character;

  *characterBuffer++ = '\n';
  *characterBuffer = '\0';

  characterBuffer = NULL;

  return intialCharacterAddress;
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
  intialCharacterAddress = characterBuffer;

  while ((character = fgetc(filePtr)) != '\n')
    *characterBuffer++ = character;

  *characterBuffer++ = '\n';
  *characterBuffer = '\0';

  characterBuffer = NULL;

  return intialCharacterAddress;
}

/**************************************/
/* Read a lines, Returns an array */
/**************************************/

#if 0
char **ereadLines(FILE *filePtr)
{
  if (filePtr == NULL)
    filePtr = mainFilePtr;

  char character;

  // lineBuffer = (char **)malloc(MAX_LINE_BUFFER_LENGTH * sizeof(char));
  characterBuffer = (char *)malloc(MAX_CHARACTER_BUFFER_LENGTH * sizeof(char));
  intialCharacterAddress = characterBuffer;
  intialLineAddress = lineBuffer;

  while ((character = fgetc(filePtr)) != EOF)
  {
    *characterBuffer++ = character;
    if (character == '\n')
    {
      *characterBuffer++ = '\n';
      *characterBuffer = '\0';
      // Error
      lineBuffer = intialCharacterAddress;
      lineBuffer++;
      characterBuffer = (char *)malloc(MAX_CHARACTER_BUFFER_LENGTH * sizeof(char));
      intialCharacterAddress = characterBuffer;
    }
  }

  characterBuffer = NULL;
  lineBuffer = NULL;

  return intialLineAddress;
}

#endif

/**************************************/
/* EOF */
/**************************************/
