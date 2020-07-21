#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return:the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_height(tree));
}
/**
 * recursive_btree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return:the height of the tree
 */
size_t recursive_btree_height(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (!tree)
		return (-1);
	left_height = recursive_btree_height(tree->left);
	right_height = recursive_btree_height(tree->right);
	if (left_height > right_height)
		return (left_height += 1);
	return (right_height += 1);
}
