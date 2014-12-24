#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "dict.h"

#define CMDLEN 100

// pretty print dictionaries
void dict_print(dict *d) {
	printf("dict {\n");
	dict_list(d);
	printf("}\n");
}

void usage(char *name) {
	fprintf(stderr, "usage: %s bucket-size\n[add | rm] str\n", name);
}

int main(int argc, char **argv) {

	if (argc != 2) {
		usage(argv[0]);
		return EXIT_FAILURE;
	} else {
		dict *d = dict_init(atoi(argv[1])); // bucket size

		while (true) {

			char *str = malloc(CMDLEN * sizeof(char));
			if (str == NULL) {
				fprintf(stderr, "allocation: %s\n", strerror(errno));
			}

			ssize_t r = read(STDIN_FILENO, str, (CMDLEN - 1) * sizeof(char));
			if (r == 0) {
				// if nothing is read, its equivalent to eof.
				break;
			}
			str[r - 1] = '\0'; // overwrite newline

			char *cmd = strtok(str, " ");
			str += strlen(cmd) + 1; // ignore first token

			if (strcmp(cmd, "add") == 0) {
				printf("haha!\n");
				dict_add(d, str);
				dict_print(d);
			} else if (strcmp(cmd, "rm") == 0) {
				dict_rm(d, str);
				dict_print(d);
			}
		}

		dict_list(d); // print dict contents
	}
}
