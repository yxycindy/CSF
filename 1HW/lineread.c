#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readin(char *key) {				//should only read line 
	char c = fgetc(stdin);			//read doc this returns an int
	int find = 1;

	while (c != EOF) {				//
		int i = 0;
		int size = 20;				// make it 1 
		// don't need cast
		char *lineBuffer = (char*)malloc(sizeof(char) * size);
		while (c != '\n') {
			lineBuffer[i++] = c;
			c = fgetc(stdin);
			if (i == size - 1) {
				//only need to copy once change the pointer 
				//wrtie a for loop to copy 
				char *temp = (char*)malloc(sizeof(char) * size);
				strcpy(temp, lineBuffer);
				size = size * 2;
				free(lineBuffer);
				lineBuffer = (char*)malloc(sizeof(char) * size);
				strcpy(lineBuffer, temp);
				free(temp);
			}
		}

		// whenever print or use it as a string, add a 0 at the end.
		if (strstr(lineBuffer, key) != NULL) {
			find = 0;
			printf("%s\n", lineBuffer);
		}
		free(lineBuffer);
		c = fgetc(stdin);
	}
	return find;
}
