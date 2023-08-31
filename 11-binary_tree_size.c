#include "binary_trees.h"

/**
 * binary_tree_size - Calculate the size of a binary tree
 * @tree: The root node to start the calculation from
 * Return: The total number of nodes in the tree rooted at `root`
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}
