#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree, or 0 if  tree si NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * swap - Swaps 2 nodes in a binary tree
 * @a: First node
 * @b: Second node
 */
void swap(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify - Heapifies a binary tree
 * @node: Pointer to the root node of the tree to heapify
 */

void heapify(heap_t *node)
{
	heap_t *max = node;

	if (node->left != NULL && node->left->n > max->n)
		max = node->left;

	if (node->right != NULL && node->right->n > max->n)
		max = node->right;

	if (max != node)
	{
		swap(node, max);
		heapify(max);
	}
}

/**
 * heap_insert - Inserts a value in Max Binary GHeap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = *root;
	while (parent->left != NULL && parent->right != NULL)
	{
		if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
