/**
* Copyrigth © 2015, All rights reserved.
* fileManager.c
* Author: Fernando Segovia Salgado
*/
#include "../Headers/fileManager.h"

/**
 * Opens a char with a set options
 * @param filename the filename with its etension and/or the path.
 * @param options the set of options: ej: w, r, rw
 * @return the opened file
 */
FILE* openFile(char *filename, char *options) {
	FILE *file = fopen(filename, options);
	return file;
}

/**
 * Writes a message into a file
 * @param file the file to be written
 * @param message the message that will be written in the file
 */
void writeInFile(FILE *file, char *message) {
	fprintf(file, "%s\n", message);
}

void getNextLine(FILE *file, char *singleLine){
	fgets(singleLine,150,file);
}

/**
 * Closes a file
 * @param file the file to be closed
 */
void closeFile(FILE *file) {
	fclose(file);
}