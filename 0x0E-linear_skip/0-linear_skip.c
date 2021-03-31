#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 * @list: list is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 * Return: return a pointer on the first node where value is located or NULL on failure
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end;

	if (!list)
		return (NULL);
	start = list;
	end = list->express;
	while (end)
	{
		if (value < end->n || !end->next)
			printf("Value checked at index [%lu] = [%d]\n",
			       end->index, end->n);
		if ((start->n < value && value < end->n) || end->next == NULL)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       start->index, end->index);
			break;
		}
		start = end;
		if (!(end->express) && end->next)
		{
			while (end->next)
				end = end->next;
		}
		else
			end = end->express;
	}

	while (start && start->index < end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}