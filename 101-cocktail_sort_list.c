#include "sort.h"

/**
 * swap_node_up - swaps nodes while traversing up the linked list
 *
 * @list: The linked list
 * @current: the current node
 */
void swap_node_up(listint_t **list, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev)
		(*current)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*current)->prev;
	(*current)->prev = temp;
	(*current)->next = temp->next;
	if (temp->next)
		temp->next->prev = *current;
	temp->next = *current;
	*current = temp;
}
/**
 * swap_node_down - swaps nodes while traversing down the linked list
 *
 * @list: The linked list
 * @current: Current node
 */
void swap_node_down(listint_t **list, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if (temp->prev)
		temp->prev->next = *current;
	else
		*list = *current;
	(*current)->prev = temp->prev;
	temp->prev = *current;
	temp->next = (*current)->next;
	if ((*current)->next)
		(*current)->next->prev = temp;
	(*current)->next = temp;
	*current = temp;
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

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped == 1)
	{
		swapped = 0;
		for (current = *list; current && current->next; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_up(list, &current);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; current && current->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_down(list, &current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}
