#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if binary is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size = 0, height = 0, total = 1, i = 0;

	if (!tree)
		return (0);

	size = recursive_btree_size(tree) + 1;
	height = recursive_btree_height(tree) + 1;

	for (i = 0; i < height; i++)
		total *= 2;

	if (size == total)
		return (1);

	return (0);
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
