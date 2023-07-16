/**************************************/
/* util.h */
/**************************************/

#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>

/**************************************/
/* Read file till delimeter */
/**************************************/

void *readTillDelimeter(char delimeter, FILE *filePtr, int readCustomLines);

#endif

/**************************************/
/* EOF */
/**************************************/
