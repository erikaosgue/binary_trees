#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_trees_ancestor - Lowest common ancestor
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node
 * of the two given nodes; or NULL  if ancestor was not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *root;
	binary_tree_t *first_e;
	binary_tree_t *second_e;

	if (!first || !second)
		return (NULL);
	root = find_the_root(first);
	first_e = node_in_the_tree((binary_tree_t *)first, root);
	second_e = node_in_the_tree((binary_tree_t *)second, root);

	if (first_e && second_e)
		return (recursion_btrees_ancestor(first, second, root));
	return (NULL);
}
/**
 * recursive_btrees_ancestor - Lowest common ancestor
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * @ancestor: the root of the binary tree
 * Return: a pointer to the lowest common ancestor node
 * of the two given nodes; or NULL  if ancestor was not found
 */
binary_tree_t *recursion_btrees_ancestor(const binary_tree_t *first,
const binary_tree_t *second, binary_tree_t *ancestor)
{
	binary_tree_t *ancestor_right, *ancestor_left;

	if (!ancestor)
		return (NULL);
	if (ancestor == first || ancestor == second)
		return (ancestor);

	ancestor_left = recursion_btrees_ancestor(first, second, ancestor->left);
	ancestor_right = recursion_btrees_ancestor(first, second, ancestor->right);

	if (ancestor_left && ancestor_right)
		return (ancestor);
	else if (ancestor_left)
		return (ancestor_left);
	else if (ancestor_right)
		return (ancestor_right);
	return (NULL);

}
/**
 * find_the_root - find the root of the binary tree
 * @root: the node of the subtree
 * Return: the root of the binary tree
 *
 */
binary_tree_t *find_the_root(const binary_tree_t *root)
{
	if (!root->parent)
		return ((binary_tree_t *)root);
	return (find_the_root(root->parent));
}
/**
 * node_in_the_tree - check if a node is in the tree
 * @node: node to check
 * @parent: is the root of the tree
 * Return: A pointer to the node if is in the Bninary tree
 * or NULL oterwise
 */
binary_tree_t *node_in_the_tree(binary_tree_t *node, binary_tree_t *parent)
{
	binary_tree_t *node_L, *node_R;

	if (!parent)
		return (NULL);
	if (parent == node)
		return (node);
	node_L = node_in_the_tree(node, parent->left);
	node_R = node_in_the_tree(node, parent->right);
	if (node_L || node_R)
		return (node);
	return (NULL);
}
