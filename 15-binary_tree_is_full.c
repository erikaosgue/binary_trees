#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_is_full(tree));
}
/**
 * recursive_btree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary tree is full, 0 otherwise
 */
int recursive_btree_is_full(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (!tree)
		return (1);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
		left = recursive_btree_is_full(tree->left);
	if (tree->right)
		right = recursive_btree_is_full(tree->right);
	if (left && right)
		return (1);
	return (0);

}
