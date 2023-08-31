#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: this function must return a pointer to the root node of the created
 * BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	int index;
	bst_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (index = 0; index < (int)size; index++)
		bst_insert(&root, array[index]);
	return (root);
}
