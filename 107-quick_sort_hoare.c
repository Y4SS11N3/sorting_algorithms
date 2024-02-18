#include "sort.h"

/**
 * swap - Swaps two integers in the array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int tmp = *a;
	(void)array;
	(void)size;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme.
 * @array: The array to sort.
 * @low: The starting index of the array to sort.
 * @high: The ending index of the array to sort.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = low - 1, below = high + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below, array, size);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * quick_sort_hoare_rec - Implements the quicksort algorithm recursively.
 * @array: The array to sort.
 * @low: The starting index of the array to sort.
 * @high: The ending index of the array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare_rec(int *array, int low, int high, size_t size)
{
	int part;

	if (high - low > 0)
	{
		part = hoare_partition(array, low, high, size);
		quick_sort_hoare_rec(array, low, part - 1, size);
		quick_sort_hoare_rec(array, part, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the quicksort algorithm with Hoare partition scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_hoare_rec(array, 0, size - 1, size);
}

