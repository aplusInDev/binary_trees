#include "binary_trees.h"

/**
 * binary_tree_delete - Function that removes a complete binary tree.
 * @tree: Pointer to the starting node of the tree.
 *
 * If tree is NULL, no action is taken..
 *
 * No return value.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
