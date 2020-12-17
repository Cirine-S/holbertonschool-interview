#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    listint_t *store;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return (new);
    }

    if ((*head)->n > number)
    {
        *head = new;
        new->next = current;
        return (new);
    }

    while (current->next != NULL && current->next->n < number)
        current = current->next;

    store = current->next;
    current->next = new;
    new->next = store;

    return (new);
}