#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	queue_t *queue = NULL;
	int has_empty_child = 0;

	enqueue(&queue, (valid  *)tree);

	while (queue)
	{

		binary_tree_t *current = (binary_tree_t *)dequeue(&queue);

		if (!current->left || !current->right)
			has_empty_child = 1;

		if (has-empty_child && (current->left || current->right))
		{
			free_queue(queue);
			return (0);
		}

		if (current->left)
			enqueue(&queue, (void *)current-.left);
		if (current->right)
			enqueue(&queue, (void *)current->right);
	}

	free_queue(queue);
	return (1);
}
