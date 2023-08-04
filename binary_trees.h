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

/* Function to count the leaves ina binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Function to count the nodes with at least 1 child in a binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Function to measure the balance factor of a binary tree */
int binary_tree_balance(const binary_tree_t *tree);

/* Function to Check if a binary tree is full */
binary_tree_is_full(const binary_tree_t *tree);

/* Function to check if a binary tree is perfect */
int binary_tree_is perfect(const binary_tree_t *tree);

/* Function to find the sibling of a node */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Function to find the uncle of a node */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Function to find the lowest common ancestor of 2 nodes */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* Function to traverse a binary tree usinig level-order traversal */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Advanced tasks additions*/
int binary_tree_is_ancestor(const binary_tree_t *node, const binary_tree_t *target);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int is_bst_util(const binary_tree_t *tree, const binary_tree_t **prev);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
#endif /* BINARY_TREES_H*/
