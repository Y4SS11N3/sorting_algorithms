#include "deck.h"

/**
 * get_card_value - Gets the value of a card.
 * @card: The card to get the value of.
 *
 * Return: The value of the card.
 */
int get_card_value(const card_t *card)
{
	const char *values = "A234567891JQK";
	int i;

	for (i = 0; values[i]; i++)
	{
		if (values[i] == card->value[0])
		{
			return (i + (card->kind * 13));
		}
	}
	return (-1);
}

/**
 * compare_cards - Compares two cards.
 * @a: The first card to compare.
 * @b: The second card to compare.
 *
 * Return: The difference of the values of the cards.
 */
int compare_cards(const void *a, const void *b)
{
	deck_node_t *cardA = *(deck_node_t **)a;
	deck_node_t *cardB = *(deck_node_t **)b;

	int valueA = get_card_value(cardA->card);
	int valueB = get_card_value(cardB->card);

	return (valueA - valueB);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: The deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp;
	deck_node_t *arr[52];
	int i = 0;

	if (!deck || !*deck)
	{
		return;
	}

	temp = *deck;

	while (temp)
	{
		arr[i++] = temp;
		temp = temp->next;
	}

	qsort(arr, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 51; i++)
	{
		arr[i]->next = arr[i + 1];
		arr[i + 1]->prev = arr[i];
	}
	arr[0]->prev = NULL;
	arr[51]->next = NULL;
	*deck = arr[0];
}

