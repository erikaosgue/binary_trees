#include "binary_trees.h"
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

	if (!first || !second)
		return (NULL);
	if (first->n == second->n)
		return (NULL);

	root = find_the_root(first);
	return (recursion_btrees_ancestor(first, second, root));
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
	if (ancestor->n == first->n || ancestor->n == second->n)
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
