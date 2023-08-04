#include "binary_trees.h"
#include <stdlib.h>
/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (root == NULL || *root == NULL)
		return (0);

	int value = (*root)->n;
	heap_t *last_node = find_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	swap_nodes(*root, last_node);
	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	free(last_node);
	heapify_down(*root);

	return (value);
}
