#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: A pointer to the new root of the binary tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *child = NULL;

	if (!tree)
		return (NULL);

	if (tree->left)
		root = tree->left;

	if (root->right)
		child = root->right;

	tree->parent = root;
	tree->left = NULL;
	root->right = tree;
	root->parent = NULL;

	if (child)
		tree->left = child;

	return (root);
}
