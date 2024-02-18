#include "sort.h"

/**
 * get_max - Finds the maximum number in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * counting_sort_radix - A subroutine of radix sort
 * that sorts the digits of the
 * array's elements based on the current significant digit (exponent).
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current significant digit to sort by.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int i, count[10] = {0};

	if (!output)
	{
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (!array || size < 2)
	{
		return;
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

