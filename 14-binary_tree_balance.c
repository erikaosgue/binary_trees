#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of the binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (!tree)
		return (0);
	left_height = recursive_btree_balance(tree->left);
	right_height = recursive_btree_balance(tree->right);
	return (left_height - right_height);

}
/**
 * recursive_btree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of the binary tree
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
