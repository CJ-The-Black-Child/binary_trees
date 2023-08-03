#include "binary_trees.h"
#include "queues.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a functio  to call for each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	queue_t *queue = NULL;

	enqueue(&queue, (void *)tree);

	while (queue)
	{
		binary_tree_t *current = (binary_tree_t *)dequeue(&queue);

		func(current->n);

		if (current->left)
			enqueue(&queue, (void *)current->left);
		if (current->right)
			enqueue(&queue, (void *)current->right);
	}

	free_queue(queue);
}
