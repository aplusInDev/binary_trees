#include "binary_trees.h"

/**
 * bst_search -  Searches for a specified value in a Binary Search Tree
 * @tree: pointer to the root node of the Binary Search Tree
 * @value: value to search for in the tree
 * Return: Pointer to the node containing the specified value, or NULL if
 * the value is not found or the tree is empty
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}
	return (NULL);
}
