#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves the tree have
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_leaves(tree));
}

/**
 * recursive_btree_leaves - counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 * Return: the number of leaves the tree have
 */
size_t recursive_btree_leaves(const binary_tree_t *tree)
{
	size_t leaves_L = 0;
	size_t leaves_R = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	leaves_L = recursive_btree_leaves(tree->left);
	leaves_R = recursive_btree_leaves(tree->right);
	return (leaves_L + leaves_R);
}
