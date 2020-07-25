#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: A pointer to the new root of the binary tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *child = NULL;

	if (!tree)
		return (NULL);

	if (tree->right)
		root = tree->right;

	if (root->left)
		child = root->left;

	tree->parent = root;
	tree->right = NULL;
	root->left = tree;
	root->parent = NULL;

	if (child)
		tree->right = child;

	return (root);
}
