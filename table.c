
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "table.h"

// looks through table for correct entry,
// returns entry if found, NULL if does not exist.
table *table_get(table *tab, char *key) {
	while (strcmp(tab->str, key) != 0) {
		if (tab->next != NULL)  {
			tab = tab->next;
		} else {
			tab = NULL;
			break; // exit loop, entry does not exist.
		}
	}
	return tab;
}

// adds table as the next of the last node in the list.
// if tab is NULL, returns new.
table *table_add(table *tab, table *new) {
	if (tab == NULL) {return new;}
	table *otab = tab;
	while (tab->next != NULL) {
		tab = tab->next;
	}
	tab->next = new;
	return otab; // return original ptr
}

// returns formatted string listing table
char *table_list(table *tab) {
	char *str = calloc(sizeof(char), 100);
	while (tab != NULL) {
		strcat(str, "'");
		strcat(str, tab->str);
		strcat(str, "', ");
		tab = tab->next;
	}
	return str;
}

// init table with default 0 values & str
table *table_init(char *str) {
	table *tab = calloc(1, sizeof(table));
	tab->str = str;
	return tab;
}
