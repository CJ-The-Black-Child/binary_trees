#include "binary_trees.h"

/**
 * is_complete - Checks if a binary tree is complete
 * @tree:Pointer to the root node of the tree
 * @index: index of the current node
 * @count: Total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int count)
{
	if (tree == null)
		return (1);

	if (index >= count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, count) &&
			is_complete(tree->right, 2 *index + 2, count ));
}

/**
 * is_heap - Checks if a binary tree is a max heap
 * @tree: Pointer to the root of the tree
 * @parent_val: Value pf the parent node
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int is_heap(const binary_tree_t *tree, int parent_val)
{
	if (tree == NULL)
		return (1);

	if (tree->n > parent_val)
		return (is_heap(tree->left, tree->n) &&
				is_heap(tree->right, tree->n));
	else
		return (0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_complete(tree, 0, binary_tree_size(tree)) &&
			is_heap(tree, tree->n))
		return (1);

	return (0);
}
