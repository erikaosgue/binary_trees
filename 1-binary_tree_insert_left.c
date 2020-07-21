#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *@parent: is a pointer to the parent node of the node to create
 *@value: is the value to put in the new node
 *Return: A pointer to the new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *new_child;
	binary_tree_t *old_child;

	if (parent == NULL)
		return (NULL);

	new_child = malloc(sizeof(binary_tree_t));
	if (!new_child)
		return (NULL);
	/* union del hijo al padre */
	new_child->left = NULL;
	new_child->right = NULL;
	new_child->n = value;
	new_child->parent = parent;
	if (parent->left != NULL)
	{
		old_child = parent->left;
		new_child->left = old_child;
		old_child->parent = new_child;
	}
	parent->left = new_child;
	new_child->parent = parent;
	return (new_child);
}
