#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of the list
 * Return: 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int i = 0;
	int len = 0;
	int arr[100];

	if (!*head)
		return (1);

	while (current)
	{
		arr[len] = current->n;
		current = current->next;
		len++;
	}

	while (i <= len / 2)
	{
		if (arr[i] != arr[len - i - 1])
			return (0);
		i++;
	}
	return (1);
}
