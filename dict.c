
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "dict.h"
#include "hash.h"

dict *dict_init(ssize_t sz) {
	dict *d = malloc(sizeof(dict));
	d->sz = sz;
	d->arr = calloc(sizeof(table *), sz);
	return d;
}

ssize_t dict_add(dict *d, char *str) {
	uint64_t h = hash(str) % d->sz;
	table *t = table_init(str);
	d->arr[h] = table_add(d->arr[h], t);
	return h;
}

void dict_rm(dict *d, char *str) {
	uint64_t h = hash(str) % d->sz;
	table_rm(&d->arr[h], str);
}

void dict_list(dict *d) {
	for (int i = 0; i < d->sz; i++) {
		if (d->arr[i] != NULL) {
			printf("entry %d -> %s\n", i, table_list(d->arr[i]));
		}
	}
}
