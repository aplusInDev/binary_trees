#include "binary_trees.h"

/**
 * binary_tree_size - get the size of a binary tree
 * @tree: the binary tree
 * Return: number of nodes in the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

/**
 * check_is_complete - binary_tree_is_complete helper
 * @root: tree
 * @index: index of the node
 * @size: size of the tree
 * Return: 0 (not complete) | 1 (complete)
 */
int check_is_complete(const binary_tree_t *root, int index, int size)
{

	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (check_is_complete(root->left, 2 * index + 1, size)
		&& check_is_complete(root->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - check if a binary tree is complete
 * @tree: tree
 * Return: 0 (not complete) | 1 (complete)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_is_complete(tree, 0, (int)binary_tree_size(tree)));
}

/**
 * is_heap - checks if heap
 * @tree: tree
 * Return: 0 or 1
 */
int is_heap(const binary_tree_t *tree)
{
	if (tree->left)
	{
		if (!is_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (!is_heap(tree->right))
			return (0);
	}
	if (!tree->parent)
		return (1);
	if (tree->n < tree->parent->n)
		return (1);
	return (0);
}
/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: this function must return 1 if tree is a valid Max Binary Heap, and
 * 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_heap(tree) && binary_tree_is_complete(tree))
		return (1);
	return (0);
}
