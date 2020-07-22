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
	if (!second->parent)
		return (NULL);
	if (second->parent == first)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return (first->parent);
	return (binary_trees_ancestor(first, second->parent));
}
