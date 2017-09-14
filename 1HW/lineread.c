#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readin() {
	char *str;
	int ch;
	int index = 0;
	int size = 1;
	str = malloc(sizeof(char) * size);
	if (str == NULL) { exit(1);}

	while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
		str[index++] = ch;

		if(index == size){
			size = size * 2;
			char *newStr = malloc(sizeof(char) * size);
			if (str == NULL) { exit(1);}
			for (int i = 0; i < index; i++) {
				newStr[i] = str[i];
			}
			free(str);
			str = newStr;
		}
	}

	if(index == 0 && ch == EOF) {
		free(str);
		return NULL;
	}
	str[index++] = '\0';
	return realloc(str, sizeof(char) * index);
}
