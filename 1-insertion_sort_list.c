#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			if (temp->prev != NULL)
			{
				temp->prev->next = current;
			}
			temp->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = temp;
			}
			current->next = temp;
			temp->prev = current;
			if (current->prev == NULL)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
