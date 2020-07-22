#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 * Return: A pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);
	if (!node->parent->parent)
		return (NULL);
	parent = node->parent;
	if (parent->parent->left == parent)
		return (parent->parent->right);
	return (parent->parent->left);

}
