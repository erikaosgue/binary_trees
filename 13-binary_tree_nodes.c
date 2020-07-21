#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child
 * in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: the number of nodes with at least 1 child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (recursive_btree_nodes(tree));

}
/**
 * recursive_btree_nodes - counts the nodes with at least 1 child
 * in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: the number of nodes with at least 1 child
 */
size_t recursive_btree_nodes(const binary_tree_t *tree)
{
	size_t node_L = 0;
	size_t node_R = 0;

	if (!tree)
		return (0);
	node_L = recursive_btree_nodes(tree->left);
	node_R = recursive_btree_nodes(tree->right);
	if (tree->left || tree->right)
		return (node_L + node_R + 1);
	return (node_R + node_L);
}
