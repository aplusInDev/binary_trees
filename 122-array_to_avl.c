#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array:  a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return:  function must return a pointer to the root node of the created
 * AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	int i;
	bst_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
