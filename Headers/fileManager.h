/**
* Copyrigth © 2015, All rights reserved.
* fileManager.h
* Author: Fernando Segovia Salgado
*/
#include <stdlib.h>
#include <stdio.h>

#ifndef FILE_WRITER_H_
#define FILE_WRITER_H_

FILE* openFile(char *filename, char *options);
/* TODO: read */
void writeInFile(FILE *file, char *message);
void closeFile(FILE *file);

#endif // FILE_WRITER_H_