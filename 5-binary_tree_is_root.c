#include "binary_trees.h"

/**
 * binary_tree_is_root - function that determines if a given node is a root.
 * @node: Pointer to the node to be checked.
 *
 * Returns: 1 if the node is a root, otherwise 0. Returns 0 if the node is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
		return (1);
	return (0);
}
