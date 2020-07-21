#include "binary_trees.h"

/**
 *  binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	recursive_btree_preorder(tree, func);
}

/**
 * recursive_btree_preorder - goes through a binary tree using
 * pre-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 */

void recursive_btree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	func(tree->n);
	recursive_btree_preorder(tree->left, func);
	recursive_btree_preorder(tree->right, func);
}
