#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: this function must return a pointer to the root node of the created
 * Binary Heap, or NULL on failure
 */
avl_t *array_to_heap(int *array, size_t size)
{
	int i;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		heap_insert(&root, array[i]);
	return (root);
}
