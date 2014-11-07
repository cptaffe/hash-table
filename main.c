#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "dict.h"

int strlcmp(char *str, char *other) {
	for (int i = 0; str[i] != '\0' && other[i] != '\0'; i++) {
		int diff = str[i] - other[i];
		if (diff != 0) {return diff;}
	}
	return 0;
}

void dict_print(dict *d) {
	printf("dict {\n");
	dict_list(d);
	printf("}\n");
}

int main(int argc, char *argv[]) {

	if (argc < 2) {return 1;}

	dict *d = dict_init(atoi(argv[1])); // bucket size

	while (1) {
		char *str = malloc(100 * sizeof(char));
		ssize_t r = read(STDIN_FILENO, str, 100 * sizeof(char));
		if (r == 0) {break;}
		str[r - 1] = '\0';
		if (strlcmp(str, "add") == 0) {
			dict_add(d, &str[4], NULL);
			dict_print(d);
		} else if (strlcmp(str, "rm") == 0) {
			dict_rm(d, &str[3]);
			dict_print(d);
		}
	}

	dict_list(d); // print dict contents
}
