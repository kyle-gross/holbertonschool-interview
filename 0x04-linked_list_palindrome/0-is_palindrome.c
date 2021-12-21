#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - determines if a list is a palindrome
 * @head: head of list to check
 * Return: 0 if not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *temp = NULL;
	size_t len = list_len(*head);
	int half = (len / 2);

	if (!*head || len == 1)
		return (1);

	while (half > 0)
	{
		current = current->next;
		half--;
	}

	if (len % 2 != 0)
		current = current->next;

	temp = rev_list(&current);

	while (temp)
	{
		if (temp->n != (*head)->n)
			return (0);
		temp = temp->next;
		(*head) = (*head)->next;
	}

	return (1);
}

/**
 * rev_list - reverses linked list
 * @h: the list to reverse
 * Return: ptr to first node of reversed list
 */
listint_t *rev_list(listint_t **h)
{
	listint_t *temp, *trav;

	trav = *h;
	trav = trav->next;
	(*h)->next = NULL;

	while (trav)
	{
		temp = trav->next;
		trav->next = *h;
		*h = trav;
		trav =  temp;
	}
	return (*h);
}

/**
 * list_len - finds the length of the linked list
 * @h: ptr to head of list
 * Return: number of nodes
 */
size_t list_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current)
	{
		current = current->next;
		count++;
	}

	return (count);
}
