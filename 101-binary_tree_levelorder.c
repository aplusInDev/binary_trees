#include "binary_trees.h"
#include <stdlib.h>



/**
 * binary_tree_size - calculates the size of a tree
 * @tree: tree
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * saver - converts a tree to an arr in level-order traversal
 * @tree: tree
 * @tree_arr: tree array
 * @index: index
 */
void saver(const binary_tree_t *tree, int *tree_arr, int index)
{
	if (tree == NULL)
		return;
	tree_arr[index] = tree->n;
	if (tree->left)
		saver(tree->left, tree_arr, (2 * index) + 1);
	if (tree->right)
		saver(tree->right, tree_arr, (2 * index) + 2);
}

/**
 * binary_tree_levelorder - this function that goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int size, i;
	int *tree_arr;

	if (!tree || !func)
		return;
	size = binary_tree_size(tree);
	tree_arr = calloc(size, sizeof(int));
	saver(tree, tree_arr, 0);
	for (i = 0; i < size; i++)
		func(tree_arr[i]);
	free(tree_arr);
}
