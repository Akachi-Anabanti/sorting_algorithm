#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm
 *
 * @list: The linked list to manipulate
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *nextnode, *prevnode, *head;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	head = *list;
	current = head->next;

	while (current && current->prev)
	{
		swapped = 0;

		while (current->prev && current->n < current->prev->n)
		{
			prevnode = current->prev;
			nextnode = current->next;

			prevnode->next = nextnode;

			if (nextnode != NULL)
				nextnode->prev = prevnode;
			current->prev = prevnode->prev;
			current->next = prevnode;

			if (prevnode->prev)
				prevnode->prev->next = current;
			else
				*list = current;
			prevnode->prev = current;
			swapped = 1;
			if (swapped == 1)
				print_list(*list);
		}
		current = current->next;
	}
}
