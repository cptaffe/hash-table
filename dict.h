
#ifndef DICT_H_
#define DICT_H_

#include "table.h"

typedef struct {
	table **arr; // table array
	size_t sz;
} dict;

dict *dict_init(size_t sz);

size_t dict_add(dict *d, char *str, void *data);

void dict_rm(dict *d, char *str);

void dict_list(dict *d);

#endif // DICT_H_
