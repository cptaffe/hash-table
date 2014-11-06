#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char *argv[]) {

	if (argc < 2) {return 1;}

	int m = atoi(argv[1]); // bucket size

	size_t size = 100 * sizeof(char);
	char *str = malloc(size);

	ssize_t r;
	while ((r = read(STDIN_FILENO, str, size)) != 0) {
		str[r - 1] = '\0';
		printf("'%s' -> %llu\n", str, hash(str) % m);
	}
}
