#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: A pointer to the new root of the binary tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *child = NULL, *parent = NULL;

	if (!tree || !tree->left)
		return (NULL);

	root = tree->left;
	child = root->right;
	parent = tree->parent;

	root->right = tree;
	tree->left = child;
	if (child)
		child->parent = tree;
	tree->parent = root;
	root->parent = parent;
	if (parent)
	{
		if (parent->left != tree)
			parent->right = root;
		else
			parent->left = root;

	}
	return (root);
}
