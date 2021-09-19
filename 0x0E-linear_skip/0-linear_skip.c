#include "search.h"
/**
 * linear_skip - Searches for a values.
 * @list: pointer
 * @value: value t
 *
 * Return: pointer
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = list;

	if (!list)
		return (NULL);

	while (list->n < value && list->express)
	{
		prev = list;
		list = list->express;
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);
	}

	if (value <= list->n)
		printf("Value found between indexes [%ld] and [%ld]\n",
				prev->index, list->index);
	else
	{
		prev = prev->express;
		while (list->next)
			list = list->next;
		printf("Value found between indexes [%ld] and [%ld]\n",
				prev->index, list->index);
	}

	while (prev)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
