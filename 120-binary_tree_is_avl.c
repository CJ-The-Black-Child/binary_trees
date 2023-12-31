#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_height = Measures the height of a binary tree
 * @tree: Pointer to the root node  of the tree.
 *
 * Return: The height of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (tree == NULL)
		return (0);




	return (1 + (left_height > right_height ? left_height :  right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid AVL Tree, 0 Otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);

	if (tree == NULL)
		return (0);

	if (abs(left_height = right_height) > 1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);
	return (1);
}
