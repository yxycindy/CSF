#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readin(char *key) {
	char c = fgetc(stdin);
	int find = 1;

	while (c != EOF) {
		int i = 0;
		int size = 20;
		char *lineBuffer = (char*)malloc(sizeof(char) * size);
		while (c != '\n') {
			lineBuffer[i++] = c;
			c = fgetc(stdin);
			if (i == size - 1) {
				char *temp = (char*)malloc(sizeof(char) * size);
				strcpy(temp, lineBuffer);
				size = size * 2;
				free(lineBuffer);
				lineBuffer = (char*)malloc(sizeof(char) * size);
				strcpy(lineBuffer, temp);
				free(temp);
			}
		}

		if (strstr(lineBuffer, key) != NULL) {
			find = 0;
			printf("%s\n", lineBuffer);
		}
		free(lineBuffer);
		c = fgetc(stdin);
	}
	return find;
}
