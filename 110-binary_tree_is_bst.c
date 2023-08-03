#include "binary_trees.h"

/**
 * is_bst_util - Recursive function to check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @prev: Pointer to the previousy visited node (NULL initially).
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, const binary_tree_t **prev)
{
	if (!tree)
		return (1);

	if (!is_bst_util(tree->left, prev))
		return (0);

	if (*prev && (*prev)->n >= tree->n)
		return (0);

	*prev = tree;

	return (is_bst_util(tree->right, prev));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node  of the tree to check.
 *
 * Return: 1 if tree is a valid BST . 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	const binary_tree_t *prev = NULL;
	return (is_bst_util(tree, &prev));
}
