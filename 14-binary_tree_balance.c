#include "binary_trees.h"


/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_value, right_value, max;

	if (tree == NULL)
		return (0);

	left_value = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_value = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max = left_value > right_value ? left_value : right_value;
	return (max);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, otherways it returns the balace factor of a
 * binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_value, right_value;

	if (tree == NULL)
		return (0);

	left_value = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_value = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_value - right_value);
}

