#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: a pointer to the head of the skiplist to search in.
 * @value: the value to search for.
 *
 * Return: a pointer on the first node where value is located. NULL otherwise.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end;

	if (!list)
		return (NULL);
	start = list;
	end = start->express;
	while (end)
	{
		if (value <= end->n || end->next != NULL)
			printf("Value checked at index [%lu] = [%d]\n",
			       end->index, end->n);
		if ((start->n <= value && value <= end->n) || end->next == NULL)
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

	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
