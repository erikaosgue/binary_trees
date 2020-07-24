#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct listint_s
{
	binary_tree_t *node;
	struct listint_s *next;
} listint_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;
/* AVL Tree*/
typedef struct binary_tree_s avl_t;
/* Max Binary Heap*/
typedef struct binary_tree_s heap_t;

/* for printing the tree */
void binary_tree_print(const binary_tree_t *tree);
/* -----------------------------------------------------------*/

/* Declaration of Functions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
void delete_btree_recursion(binary_tree_t *parent);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void recursive_btree_preorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void recursive_btree_inorder(const binary_tree_t *tree, void (*func)(int));

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void recursive_btree_postorder(const binary_tree_t *tree, void (*func)(int));

size_t binary_tree_height(const binary_tree_t *tree);
size_t recursive_btree_height(const binary_tree_t *tree);

size_t binary_tree_depth(const binary_tree_t *tree);
size_t recursive_btree_depth(const binary_tree_t *tree);

size_t binary_tree_size(const binary_tree_t *tree);
size_t recursive_btree_size(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);
size_t recursive_btree_leaves(const binary_tree_t *tree);

size_t binary_tree_nodes(const binary_tree_t *tree);
size_t recursive_btree_nodes(const binary_tree_t *tree);

int binary_tree_balance(const binary_tree_t *tree);
int recursive_btree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);
int recursive_btree_is_full(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
binary_tree_t *find_the_root(const binary_tree_t *root);
binary_tree_t *recursion_btrees_ancestor(const binary_tree_t *first,
const binary_tree_t *second, binary_tree_t *ancestor);
binary_tree_t *node_in_the_tree(binary_tree_t *node, binary_tree_t *parent);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *pop_listint(listint_t **head);
listint_t *add_nodeint_end(listint_t **head, const binary_tree_t *node);

int binary_tree_is_complete(const binary_tree_t *tree);
#endif /* BINARY_TREES_H */
