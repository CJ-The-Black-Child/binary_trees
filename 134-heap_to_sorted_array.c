#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Addres to store the size of the array
 * Return: Pointer to the sorted array of integers (descending order)
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	if (heap == NULL || size == NULL)
		return (NULL);

	size_t heap_szie = binary_tree_size(heap);
	int *sorted_array = malloc(sizeof(int) * heap_size);
	if (sorted_array == NULL)
		return (NULL);

	for (size_t i = 0; i < heap_size; i++)
	{
		int value = heap_extract(&heap);
		sorted_array[i] = value;
	}

	*size = heap_size;
	return (sorted_array);
}
