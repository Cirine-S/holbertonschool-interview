#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t *child = malloc(sizeof(binary_tree_t));
    if (child == NULL)
        return NULL;
    
    child->parent = parent;
    child->n = value;
    child->right = NULL;
    child->left = NULL;
    return child;
    
    return (*root);
}