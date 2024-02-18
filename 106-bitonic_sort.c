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
void bitonic_merge(int *array, size_t size, int low, int cnt, int dir)
{
	size_t i, jump = cnt / 2;

	if (cnt > 1)
	{
		for (i = low; i < low + jump; i++)
		{
			if ((dir == 1 && array[i] > array[i + jump]) ||
			    (dir == 0 && array[i] < array[i + jump]))
				swap(array + i, array + i + jump, array, size);
		}
		bitonic_merge(array, size, low, jump, dir);
		bitonic_merge(array, size, low + jump, jump, dir);
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
void bitonic_sort_rec(int *array, size_t size, int low, int cnt, int dir)
{
	size_t cut = cnt / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		printf("Merging [%u/%lu] (%s):\n", cnt, size, str);
		print_array(array + low, cnt);

		bitonic_sort_rec(array, size, low, cut, 1);
		bitonic_sort_rec(array, size, low + cut, cut, 0);
		printf("Result [%u/%lu] (%s):\n", cnt, size, str);
		print_array(array + low, cnt);

		bitonic_merge(array, size, low, cnt, dir);
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

