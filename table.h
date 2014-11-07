
#ifndef TABLE_H_
#define TABLE_H_

// linked list of tables
struct table {
	char *str; // data indexing by
	struct table *next;
};

typedef struct table table;

// looks through table for correct entry,
// returns entry if found, NULL if does not exist.
table *table_get(table *tab, char *key);

// adds table as the next of the last node in the list.
// if tab is NULL, returns new.
table *table_add(table *tab, table *new);

// returns formatted string listing table
char *table_list(table *tab);

// init table with default 0 values & str
table *table_init(char *str);

#endif // TABLE_H_
