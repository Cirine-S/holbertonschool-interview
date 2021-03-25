#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * create_node - set the left AVL node of a parent node
 * @array: pointer to the 1st element of the array to create the subarray from
 * @parent: pointer to the parent node of the node to be created
 * @start: start index of the subarray
 * @end: end index of the subarray
 * Return: pointer to the address of the generated AVL node
 */
avl_t *create_node(int *array, avl_t *parent, int start, int end)
{
	avl_t *node;
	int sum, middle, n;

	if (start > end)
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	sum = start + end;
	middle = (sum / 2);
	n = array[sum / 2];

	node->parent = parent;
	node->n = n;
	node->left = create_node(array, node, start, middle - 1);
	node->right = create_node(array, node, middle + 1, end);
	return (node);
}


/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: a pointer to the 1st element of the array to be converted
 * @size: the number of the elements of the array
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	int n, middle, start, end;

	if (size <= 0 || !array)
		return (NULL);

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	start = 0;
	end = size - 1;
	middle = (start + end) / 2;
	n = array[(start + end) / 2];

	root->parent = NULL;
	root->n = n;
	root->left = create_node(array, root, start, middle - 1);
	root->right = create_node(array, root, middle + 1, end);
	return (root);
}
