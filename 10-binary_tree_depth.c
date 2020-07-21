#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_depth(tree));
}
/**
 * recursive_btree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: the depth of the tree
 */
size_t recursive_btree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (-1);
	depth = recursive_btree_depth(tree->parent);
	depth += 1;
	return (depth);
}
