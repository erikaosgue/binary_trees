#include "binary_trees.h"
/**
 * binary_tree_ancestor - Lowest common ancestor
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node
 * of the two given nodes; or NULL  if ancestor was not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (!first && !second)
		return (NULL);
	/* if first is first */
	if (second->parent == first || second->parent->parent == first)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return (first->parent);
	/* if second node is first */
	if (first->parent == second || first->parent->parent == second)
		return ((binary_tree_t *)second);
	if (!second->parent || !first->parent)
		return (NULL);
	return (binary_trees_ancestor(first->parent, second->parent));
}
