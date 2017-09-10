#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lineread.h"
int main (int argc, char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, "error: no pattern specififed\n");
		exit(2);
	}

	char *key = argv[1];
	readin(key);

	return (EXIT_SUCCESS);
}
