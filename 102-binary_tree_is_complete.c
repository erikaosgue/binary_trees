#include "binary_trees.h"
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 If binary tree is complete, 0 otherwise
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *temp;
	listint_t *head = NULL;
	int btree_complete = 0;

	if (!tree)
		return (0);

	add_nodeint_end(&head, tree);
	while (head)
	{
		temp = pop_listint(&head);
		if (temp->left)
		{
			if (btree_complete)
			{
				free_listint(head);
				return (0);
			}
			add_nodeint_end(&head, temp->left);
		}
		else
			btree_complete = 1;
		if (temp->right)
		{
			if (btree_complete)
			{
				free_listint(head);
				return (0);
			}
			add_nodeint_end(&head, temp->right);
		}
		else
			btree_complete = 1;
	}
	return (1);
}
/**
 * add_nodeint_end - adds a new node at the end of a listint_t list.
 * @head: Its a pointer to the address of the the *head in main.c
 * @node: the node of the to be enter as data in the linked list
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
/**
 * free_listint - frees a listint_t list.
 * @head: The address of the head pointer
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *t;
	int i;

	for (i = 0; head != NULL; i++)
	{
		t = head;
		head = head->next;
		free(t);
	}
}
