#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *@tree: is a pointer to the root node of the tree to delete
 *If tree is NULL, do nothing
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	delete_btree_recursion(tree);
}
/**
 * delete_btree_recursion - resursion funcition for deleting a tree
 * @parent: actual parent of the subtree
 */
void delete_btree_recursion(binary_tree_t *parent)
{
	if (parent == NULL)
		return;
	delete_btree_recursion(parent->left);
	delete_btree_recursion(parent->right);
	/* lo que realiza la funcion una vez retorne de ambas funciones */
	free(parent);
}
