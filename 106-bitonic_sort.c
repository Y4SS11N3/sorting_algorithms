#include "sort.h"

/**
 * swap - Swaps two elements if they are in the wrong order
 * @a: pointer to the first element
 * @b: pointer to the second element
 * @array: Unused in this context, included to match prototype in sort.h
 * @size: Unused in this context, included to match prototype in sort.h
 */
void swap(int *a, int *b, int *array, size_t size)
{
	int temp;
	(void)array;
	(void)size;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Merges and sorts a bitonic sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 * @low: Starting index of the sequence.
 * @cnt: Number of elements to be sorted.
 * @dir: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t cnt, char dir)
{
	size_t i, jp = cnt / 2;

	if (cnt > 1)
	{
		for (i = low; i < low + jp; i++)
		{
			if ((dir == 1 && array[i] > array[i + jp]) ||
				(dir == 0 && array[i] < array[i + jp]))
				swap(array + i, array + i + jp, array, size);
		}
		bitonic_merge(array, size, low, jp, dir);
		bitonic_merge(array, size, low + jp, jp, dir);
	}
}

/**
 * bitonic_sort_rec - Recursively sorts a bitonic sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 * @low: Starting index of the sequence.
 * @cnt: Number of elements to be sorted.
 * @dir: The direction to sort in.
 */
void bitonic_sort_rec(int *array, size_t size,
		size_t low, size_t cnt, char dir)
{
	size_t ct = cnt / 2;
	char *s = (dir == 1) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", cnt, size, s);
		print_array(array + low, cnt);

		bitonic_sort_rec(array, size, low, ct, 1);
		bitonic_sort_rec(array, size, low + ct, ct, 0);
		bitonic_merge(array, size, low, cnt, dir);

		printf("Result [%lu/%lu] (%s):\n", cnt, size, s);
		print_array(array + low, cnt);
	}
}

/**
 * bitonic_sort - Wrapper function for the recursive bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}

