#ifndef BINART_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
/* Binary Search Tree */
typedef struct binary_tree_s bst_t;
/* AVL Tree */
typedef struct binary_tree_s avl_t;
/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* Function to create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function to insert a node as the lefty-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Function to insert a node as the right-child of another node*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Function to delete an entity binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* Function to check if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Function to check if a node is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* Function to traverse a binary tree using pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Function to traverse  binary tree using in-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Function to traverse a binary tree using post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Function to measure the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Function to measure the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Function to measure the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);

#endif /* BINARY_TREES_H*/
