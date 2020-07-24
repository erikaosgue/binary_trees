#include "binary_trees.h"
/**
 *binary_tree_levelorder -
 goes through a binary tree using level-order traversal (horizontal)
 *@tree: is a pointer to the root node of the tree to traverse
 *@func
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *temp = NULL;
	listint_t *head = NULL;

	if (!tree || !func)
		return;

	temp = (binary_tree_t *)tree;
	while (temp)
	{
		func(temp->n);
		if (temp->left)
			add_nodeint_end(&head, temp->left);
		if (temp->right)
			add_nodeint_end(&head, temp->right);
		temp = pop_listint(&head);
	}
}
/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: Its a pointer to the address of the the *head in main.c
 * @n: the data of the note (an int)
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const binary_tree_t *node)
{
	listint_t *new;
	listint_t *t;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->node = (binary_tree_t *)node;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		t = *head;
		while (t->next != NULL)
			t = t->next;
		t->next = new;
	}
	return (new);
}
/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: Its a double pointer to the addres of the head pointer
 * Return: the head node’s data (n -> int).
 */
binary_tree_t *pop_listint(listint_t **head)
{
	listint_t *t;
	binary_tree_t *value_of_head = NULL;

	if (*head == NULL)
		return (0);
	t = (*head);
	value_of_head = (*head)->node;
	(*head) = (*head)->next;
	free(t);
	return (value_of_head);
}
