#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readin(char *key) {
	char c = fgetc(stdin);

	while (c != EOF) {
		int i = 0;
		int size = 20;
		char *lineBuffer = malloc(sizeof(char) * size);
		while (c != '\n') {
			lineBuffer[i++] = c;
			c = fgetc(stdin);
			if (i == size - 1) {
				char *temp = malloc(sizeof(char) * size);
				strcpy(temp, lineBuffer);
				size = size * 2;
				lineBuffer = malloc(sizeof(char) * size);
				strcpy(lineBuffer, temp);
			}
		}

		if (strstr(lineBuffer, key) != NULL) {
			printf("%s\n", lineBuffer);
		}
		free(lineBuffer);
		c = fgetc(stdin);
	}
}
