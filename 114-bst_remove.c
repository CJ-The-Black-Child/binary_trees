#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove in the tree
 *
 * Return: A pointer to the new root node of the tree after removing the
 * desired value, or NULL if the tree is empty or the value is not found.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;
			free(root);
			return (temp);
		}

		bst_t *temp = bst_find_min(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * bst_find_min - finds the minimum node in a Binary Search Tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: A poinyter to the minimum node in the tree
 */
bst_t *bst_find_min(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}
