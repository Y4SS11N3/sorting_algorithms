#include "sort.h"

/**
 * counting_sort_helper - Helper function for counting_sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @count: The count array
 * @k: The maximum value in the array
 */
void counting_sort_helper(int *array, size_t size, int *count)
{
	int *output;
	size_t i;

	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, k = 0;
	size_t i;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}

	count = calloc(k + 1, sizeof(int));
	if (!count)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	for (i = 1; i <= (size_t)k; i++)
	{
		count[i] += count[i - 1];
	}

	print_array(count, (size_t)k + 1);

	counting_sort_helper(array, size, count);

	free(count);
}
