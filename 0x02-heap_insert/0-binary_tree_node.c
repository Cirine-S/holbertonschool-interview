#include "binary_trees.h"
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *child = malloc(sizeof(binary_tree_t));
    if (child == NULL)
        return NULL;
    
    child->parent = parent;
    child->n = value;
    child->right = NULL;
    child->left = NULL;
    return child;

}