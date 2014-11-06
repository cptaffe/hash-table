#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char *argv[]) {

	if (argc < 2) {return 1;}

	int m = atoi(argv[1]); // bucket size

	char **arr = calloc(sizeof(char *), m);

	while (1) {
		char *str = malloc(100 * sizeof(char));
		ssize_t r = read(STDIN_FILENO, str, 100 * sizeof(char));
		if (r == 0) {break;}
		str[r - 1] = '\0';
		int64_t h = hash(str);
		while (arr[h % m] != NULL) {h++;}
		arr[h % m] = str;
		printf("'%s' -> %llu\n", str, h % m);
	}

	for (int i = 0; i < m; i++) {
		if (arr[i] != NULL) {
			printf("entry %d -> '%s'\n", i, arr[i]);
		}
	}
}
