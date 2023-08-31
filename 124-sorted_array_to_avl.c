#include "binary_trees.h"

/**
 * arr_to_avl - create an AVL tree from a sorted array
 * @tree: AVL tree
 * @pa: parent node
 * @arr: array of int
 * @lo: low index
 * @hi: high index
 */
void arr_to_avl(avl_t **tree, avl_t *pa, int *arr, int lo, int hi)
{
	avl_t *node;
	int mid = (lo + hi) / 2;

	if (lo > hi)
		return;
	if (lo == hi)
	{
		node = binary_tree_node(pa, arr[mid]);
		if (node == NULL)
			return;
		if (pa->n < node->n)
			pa->right = node;
		else
			pa->left = node;
		return;
	}
	node = binary_tree_node(pa, arr[mid]);
	if (node == NULL)
		return;
	if (pa == NULL)
		(*tree) = node;
	else
	{
		if (pa->n < node->n)
			pa->right = node;
		else
			pa->left = node;
	}
	arr_to_avl(tree, node, arr, lo, mid - 1); /*left*/
	arr_to_avl(tree, node, arr, mid + 1, hi); /*right*/
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array:  a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: this function must return a pointer to the root node of the
 * created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	if (size == 1)
		tree = binary_tree_node(NULL, array[0]);
	else
		arr_to_avl(&tree, tree, array, 0, size - 1);
	return (tree);
}
