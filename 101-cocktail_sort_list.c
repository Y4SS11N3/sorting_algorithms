#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @a: The first node to swap
 * @b: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
	{
		a->prev->next = b;
	}
	if (b->next)
	{
		b->next->prev = a;
	}
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
	if (b->prev == NULL)
	{
		*list = b;
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node;

	if (!list || !(*list) || !(*list)->next)
		return;

	node = *list;
	while (swapped)
	{
		swapped = 0;
		sort_pass(list, &node, &swapped, 0);

		if (!swapped)
			break;

		sort_pass(list, &node, &swapped, 0);
	}
}

/**
 * sort_pass - Makes a pass through the list in the given direction
 * @list: Double pointer to the head of the list
 * @node: Double pointer to current node
 * @swapped: Pointer to swapped flag
 * @forward: Flag for the direction of the sort
 */
void sort_pass(listint_t **list, listint_t **node, int *swapped, int forward)
{
	while ((*node) && (forward ? (*node)->next : (*node)->prev))
	{
		if ((forward && (*node)->n > (*node)->next->n) ||
			(!forward && (*node)->n < (*node)->prev->n))
		{
			swap_nodes(list, forward ? *node : (*node)->prev, forward ?
			(*node)->next : *node);
			print_list(*list);
			*node = forward ? (*node)->prev : (*node)->next;
			*swapped = 1;
		}
		else
		{
			*node = forward ? (*node)->next : (*node)->prev;
		}
	}
}
