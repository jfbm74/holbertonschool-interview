#include "lists.h"

/**
* insert_node - Inserts a number in a sorted linked list.
* @head: Pointer to the first element of the list.
* @number: Number to add to the list.
* Return: The address of the new node or NULL if failed.
**/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	if (!head)
		return (NULL);
	if (!*head)
		return (add_nodeint_end(head, number));
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;
	new->next = NULL;
	current = *head;
	if (number <= current->n)
	{
		new->next = current;
		*head = new;
		return (new);
	}
	while (1)
	{
		if (!current->next || current->next->n > number)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
	}
}
