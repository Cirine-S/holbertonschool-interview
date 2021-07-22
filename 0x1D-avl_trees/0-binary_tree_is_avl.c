#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * diff - Calculates the difference between 2 integers.
 * @a: integer one.
 * @b: integer two.
 * Return: the difference between the 2 ints.
 */
int diff(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

/**
 * max - Calculates the biggest number.
 * @a: first number.
 * @b: second number.
 * Return: the biggest of a and b.
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * height - Calculates the height of a given node in a binary tree.
 * @node: binary tree node.
 * Return: height of node.
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + max(height(node->left), height(node->right)));
}

/**
 * is_bst - Checks if a given tree is a binary search tree.
 * @node: current node to check.
 * @min: the value that the node's left key shouldn't be smaller than.
 * @max: the value that the node's right key shouldn't be bigger than.
 * Return: 1 if current subtree is a BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *node, int min, int max)
{
	int a, b;

	if (node == NULL)
		return (1);
	if (node->n <= min || node->n >= max)
		return (0);
	a = is_bst(node->left, min, node->n);
	b = is_bst(node->right, node->n, max);
	if (abs(height(node->left) - height(node->right)) <= 1 && a && b)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL.
 * @tree: The pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_bst(tree, INT_MIN, INT_MAX))
		return (1);

	return (0);
}
