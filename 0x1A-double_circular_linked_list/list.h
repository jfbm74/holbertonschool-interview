#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct List - doubly linked list
 * @str: string -
 * @prev: points to the previous
 * @next: points to the next
 *
 * Description: doubly linked list
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_begin(List **list, char *str);
List *add_node_end(List **list, char *str);

#endif /* LISTS_H */
