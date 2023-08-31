#include "binary_trees.h"
#include <limits.h>


/**
 * inorder - helper
 * @tree: tree
 * @prev: prev
 * Return: 0 or 1
 */
int inorder(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);
	if (!inorder(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);
	*prev = tree->n;
	return (inorder(tree->right, prev));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: if tree is NULL it return 0, otherways it return 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev;

	if (!tree)
		return (0);
	prev = INT_MIN;
	return (inorder(tree, &prev));
}
