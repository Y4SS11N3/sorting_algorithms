#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - Recursively sorts the array
 * @array: The array to sort
 * @start: The starting index of the partition to sort
 * @end: The ending index of the partition to sort
 * @size: The size of the array
 */
void lomuto_sort(int *array, ssize_t start, ssize_t end, size_t size)
{
	if (start < end)
	{
		int pivot_index = partition(array, start, end, size);

		lomuto_sort(array, start, pivot_index - 1, size);
		lomuto_sort(array, pivot_index + 1, end, size);
	}
}

/**
 * partition - Partitions the array using the Lomuto scheme
 * @array: The array to partition
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The final index of the pivot
 */
int partition(int *array, ssize_t start, ssize_t end, size_t size)
{
	int pivot = array[end];
	ssize_t i = start - 1;
	ssize_t j;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j], array, size);
			}
		}
	}
	if (array[end] < array[i + 1])
	{
		swap(&array[i + 1], &array[end], array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two elements in the array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 * @array: The array containing the elements to swap
 * @size: The size of the array
 */
void swap(int *a, int *b, int *array, size_t size)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}
