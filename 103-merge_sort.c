#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @temp: Temporary array for merging
 * @start: Starting index
 * @middle: Middle index of the array
 * @end: Ending index
 */
void merge(int *array, int *temp, size_t start, size_t middle, size_t end)
{
	size_t i, j, k;

	i = start;
	j = middle;
	k = start;

	while (i < middle && j < end)
	{
		if (array[i] < array[j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[j++];
		}
	}

	while (i < middle)
	{
		temp[k++] = array[i++];
	}

	while (j < end)
	{
		temp[k++] = array[j++];
	}

	for (i = start; i < end; i++)
	{
		array[i] = temp[i];
	}
}

/**
 * merge_sort_rec - Recursively sorts the subarrays
 * @array: The array to be sorted
 * @temp: Temporary array for merging
 * @start: Starting index
 * @end: Ending index
 */
void merge_sort_rec(int *array, int *temp, size_t start, size_t end)
{
	size_t middle;

	if (end - start < 2)
	{
		return;
	}

	middle = start + (end - start) / 2;

	merge_sort_rec(array, temp, start, middle);
	merge_sort_rec(array, temp, middle, end);
	merge(array, temp, start, middle, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
	{
		return;
	}

	temp = malloc(sizeof(int) * size);
	if (!temp)
	{
		return;
	}

	merge_sort_rec(array, temp, 0, size);
	free(temp);
}

