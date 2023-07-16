/**************************************/
/* efile.h */
/**************************************/

#ifndef _EFILE_H_
#define _EFILE_H_

#include <stdio.h>
#include <stdlib.h>

/**************************************/
/* Close file */
/**************************************/

#define eclose(filePtr) (fclose(filePtr))

/**************************************/
/* Free buffer */
/**************************************/

#define eFreeBuffer(bufferPtr) (free(bufferPtr))

/**************************************/
/* Open file */
/**************************************/

FILE *eopen(char *fileName, char *fileMode);

FILE *eopenr(char *fileName);

FILE *eopenw(char *fileName);

FILE *eopena(char *fileName);

/**************************************/
/* Read from file */
/**************************************/

char *eread(FILE *filePtr);

/**************************************/
/* Print to screen */
/**************************************/

void eprint(FILE *filePtr);

/**************************************/
/* Read a line */
/**************************************/

char *ereadLine(FILE *filePtr);

/**************************************/
/* Read custom number of lines */
/**************************************/

char *ereadCustomLines(FILE *filePtr, int lines);

/**************************************/
/* Write to file */
/**************************************/

int ewrite(FILE *filePtr, char *data);

#endif

/**************************************/
/* EOF */
/**************************************/
