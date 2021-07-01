#include "list.h"
/**
 * add_node_end - Add a new_node node to the end of a doubly circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new_node node
 * Return: Address of the new_node node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last;

	if (!list || !str)
		return NULL;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str;

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;
	last->next = new_node;

	new_node->next = *list;
	new_node->prev = last;
	(*list)->prev = new_node;

	return (new_node);
}

/**
 * add_node_begin - Add a new_node node to the beginning of
 * a doubly circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new_node node
 * Return: Address of the new_node node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last;

	if (!list || !str)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = str;

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	last = (*list)->prev;

	new_node->next = (*list);
	new_node->prev = last;
	(*list)->prev = last->next = new_node;
	*list = new_node;

	return (new_node);
}
