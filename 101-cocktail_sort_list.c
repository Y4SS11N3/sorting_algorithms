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
	char swapped = 1;
	listint_t *node;

	if (!list || !(*list) || !(*list)->next)
	{
		return;
	}

	while (swapped)
	{
		swapped = 0;
		node = *list;
		swapped = forward_pass(list, node);
		if (!swapped)
		{
			break;
		}
		swapped = backward_pass(list, node);
	}
}

/**
 * forward_pass - Performs a forward pass through the list
 * @list: Double pointer to the head of the doubly linked list
 * @node: Current node in the list
 *
 * Return: 1 if a swap was made, 0 otherwise
 */
char forward_pass(listint_t **list, listint_t *node)
{
	char swapped = 0;

	while (node->next)
	{
		if (node->n > node->next->n)
		{
			swap_nodes(list, node, node->next);
			print_list(*list);
			swapped = 1;
		}
		else
		{
			node = node->next;
		}
	}

	return (swapped);
}

/**
 * backward_pass - Performs a backward pass through the list
 * @list: Double pointer to the head of the doubly linked list
 * @node: Current node in the list
 *
 * Return: 1 if a swap was made, 0 otherwise
 */
char backward_pass(listint_t **list, listint_t *node)
{
	char swapped = 0;

	while (node->prev)
	{
		if (node->n < node->prev->n)
		{
			swap_nodes(list, node->prev, node);
			print_list(*list);
			swapped = 1;
		}
		else
		{
			node = node->prev;
		}
	}

	return (swapped);
}
