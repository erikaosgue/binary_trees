#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: the size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_size(tree));
}
/**
 * recursive_btree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: the size of the binary tree
 */

size_t recursive_btree_size(const binary_tree_t *tree)
{
	size_t size_l = 0;
	size_t size_R = 0;

	if (!tree)
		return (0);
	size_l = recursive_btree_size(tree->left);
	size_R = recursive_btree_size(tree->right);
	return (size_l + size_R + 1);
}


