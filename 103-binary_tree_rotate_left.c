#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: A pointer to the new root of the binary tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root = NULL, *child = NULL, *parent = NULL;

	if (!tree || !tree->right)
		return (NULL);

	root = tree->right;
	child = root->left;
	parent = tree->parent;

	root->left = tree;
	tree->right = child;
	if (child)
		child->parent = tree;
	tree->parent = root;
	root->parent = parent;
	if (parent)
	{
		if (parent->right != tree)
			parent->left = root;
		else
			parent->right = root;

	}
	return (root);
}
