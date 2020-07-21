#include "binary_trees.h"

/**
 * binary_tree_insert_right -  inserts a node as the left-child of another node
 *@parent: is a pointer to the node to insert the right-child in
 *@value: is the value to put in the new node
 *Return: A pointer to the new node or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *new_child;
	binary_tree_t *old_child;

	new_child = malloc(sizeof(binary_tree_t));
	if (!new_child || parent == NULL)
		return (NULL);
	/* union del hijo al padre */
	new_child->left = NULL;
	new_child->right = NULL;
	new_child->n = value;
	new_child->parent = parent;
	if (parent->right != NULL)
	{
		old_child = parent->right;
		new_child->right = old_child;
		old_child->parent = new_child;
	}
	parent->right = new_child;
	new_child->parent = parent;
	return (new_child);
}
