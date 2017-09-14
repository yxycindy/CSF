#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lineread.h"
int main (int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, "error: no pattern specififed\n");
		exit(2);
	}

	char *word = argv[1];
	char *line;
	int find = 1;

	while ((line = readin())!= NULL) {
		if(strstr(line, word) != NULL) {
			find = 0;
			printf("%s\n", line);
		}
	}


	if(find){
		return (EXIT_FAILURE);
	} else {
		return (EXIT_SUCCESS);
	}
}
