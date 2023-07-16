/**************************************/
/* util.c */
/**************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARACTER_BUFFER_LENGTH 10000
#define MAX_LINE_BUFFER_LENGTH 10000

char *characterBufferSingle, *initialCharacterAddressSingle;
char **characterBufferDouble, **initialCharacterAddressDouble;

char character;

/**************************************/
/* Read file till delimeter */
/**************************************/

char *readTillDelimeter(char delimeter, FILE *filePtr, int readCustomLines)
{
  characterBufferSingle = (char *)malloc(MAX_CHARACTER_BUFFER_LENGTH * sizeof(char));
  initialCharacterAddressSingle = characterBufferSingle;

  if (readCustomLines)
    for (int i = 0; i < readCustomLines; i++)
    {
      while (1)
      {
        character = fgetc(filePtr);
        if (character == EOF || character == '\n')
          break;

        *characterBufferSingle++ = character;
      }

      *characterBufferSingle++ = '\n';
      *characterBufferSingle = '\0';
    }
  else
  {
    while ((character = fgetc(filePtr)) != delimeter)
      *characterBufferSingle++ = character;

    *characterBufferSingle++ = '\n';
    *characterBufferSingle = '\0';
  }

  characterBufferSingle = NULL;

  return initialCharacterAddressSingle;
}

/**************************************/
/* EOF */
/**************************************/