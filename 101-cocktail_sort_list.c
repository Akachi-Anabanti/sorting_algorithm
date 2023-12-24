#include "sort.h"

/**
 * swap_node_up - swaps nodes while traversing up the linked list
 *
 * @list: The linked list
 * @current: the current node
 */
void swap_node_up(listint_t **list, listint_t *current)
{
	if (current->prev)
		current->prev->next = current->next;
	else
		*list = current->next;
	current->next->prev = current->prev;
	current->prev = current->next;
	current->next = current->next->next;
	if (current->next)
		current->next->prev = current;
	current->prev->next = current;
}
/**
 * swap_node_down - swaps nodes while traversing down the linked list
 *
 * @list: The linked list
 * @current: Current node
 */
void swap_node_down(listint_t **list, listint_t *current)
{
	current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	if (current->prev->prev)
		current->prev->prev->next = current;
	else
		*list = current;
	current->next = current->prev;
	current->prev = current->prev->prev;
	current->next->prev = current;
}
/**
 * cocktail_sort_list - Cocktail sort algorithm function
 *
 * @list: The list to sort;
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (!(*list) || !list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		for (current = *list; current && current->next; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_up(list, current);
				swapped = 1;
				print_list(*list);
			}
		}
		for (; current && current->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_down(list, current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
