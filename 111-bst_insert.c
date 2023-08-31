#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST for value insertion
 * @value:  Value to be stored in the new node
 *
 * Return:Pointer to the newly created node, or NULL on failure
 *         If 'tree' is NULL, the new node becomes the root node.
 *         If the given value is already present, it's ignored.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root = *tree;

	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(*tree, value);
		return (*tree);
	}
	while (root && value != root->n)
	{
		if (value < root->n)
		{
			if (!root->left)
			{
				root->left = (bst_t *)binary_tree_node(root, value);
				return (root->left);
			}
			root = root->left;
		}
		else if (value > root->n)
		{
			if (!root->right)
			{
				root->right = (bst_t *)binary_tree_node(root, value);
				return (root->right);
			}
			root = root->right;
		}
	}
	return (NULL);
}
