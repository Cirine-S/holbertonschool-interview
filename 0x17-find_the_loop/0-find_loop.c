#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
  * find_listint_loop - Find a loop in a linked list.
  *
  * @head: The head of the linked list to search.
  *
  * Return: the address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !(head->next))
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
