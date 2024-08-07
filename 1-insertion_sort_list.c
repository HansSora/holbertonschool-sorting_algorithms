#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the head of the list
* @node1: Pointer to the first node
* @node2: Pointer to the second node
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next1, *prev2, *next2;

	if (node1 == node2 || node1 == NULL || node2 == NULL)
		return;

	prev1 = node1->prev;
	next1 = node1->next;
	prev2 = node2->prev;
	next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;

	if (next2)
		next2->prev = node1;

	node2->prev = prev1;
	node2->next = next1;

	if (next1)
		next1->prev = node2;

	node1->prev = node2;
	node1->next = next2;

	print_list(*list);
}

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending order
* @list: Pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
		{
			temp = current;
			current = current->next;

			sorted = temp->prev;

			while (sorted != NULL && temp->n < sorted->n)
			{
				sorted = sorted->prev;
			}

			if (sorted == temp->prev)
				continue;

			swap_nodes(list, temp, temp->prev);
		}
}
