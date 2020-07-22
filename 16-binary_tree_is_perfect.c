#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int full = 0;
	int left_height = 0;
	int right_height = 0;
	int balance = 0;

	if (!tree)
		return (0);
	full = recursive_btree_is_full(tree);
	left_height = recursive_btree_balance(tree->left);
	right_height = recursive_btree_balance(tree->right);
	balance = left_height - right_height;
	if (balance == 0 && full)
		return (1);
	return (0);
}
/**
 * recursive_btree_balance - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary is perfect, 0 otherwise
 */
int recursive_btree_balance(const binary_tree_t *tree)
{

	int left_height = 0;
	int right_height = 0;

	if (!tree)
		return (-1);
	left_height = recursive_btree_balance(tree->left);
	right_height = recursive_btree_balance(tree->right);
	if (left_height > right_height)
		return (left_height += 1);
	return (right_height += 1);
}
/**
 * recursive_btree_is_full - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary is perfect, 0 otherwise
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
