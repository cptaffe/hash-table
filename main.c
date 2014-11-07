#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "hash.h"
#include "table.h"

int main(int argc, char *argv[]) {

	if (argc < 2) {return 1;}

	int m = atoi(argv[1]); // bucket size

	table **arr = calloc(sizeof(table *), m);

	while (1) {
		char *str = malloc(100 * sizeof(char));
		ssize_t r = read(STDIN_FILENO, str, 100 * sizeof(char));
		if (r == 0) {break;}
		str[r - 1] = '\0';
		uint64_t h = hash(str);
		arr[h % m] = table_add(arr[h % m], table_init(str));
		printf("'%s' -> %llu\n", str, h % m);
	}

	for (int i = 0; i < m; i++) {
		if (arr[i] != NULL) {
			printf("entry %d -> %s\n", i, table_list(arr[i]));
		}
	}
}
