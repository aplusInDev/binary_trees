#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another new_node
 * @parent: parent node
 * @value: new node value
 * Return: new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	if (parent->right)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	else
		new_node->right = NULL;
	new_node->n = value;
	new_node->left = NULL;
	new_node->parent = parent;
	parent->right = new_node;
	return (new_node);
}