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
	int max_num;
	size_t i;

	for (max_num = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	return (max_num);
}

/**
 * counting_sort_radix - A subroutine of radix sort
 * that sorts the digits of the
 * array's elements based on the current significant digit (exponent).
 * @array: The array to sort.
 * @size: The size of the array.
 * @exp: The current significant digit to sort by.
 * @output: A buffer to store the sorted array.
 */
void counting_sort_radix(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max_num, exp, *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max_num = get_max(array, size);
	for (exp = 1; max_num / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}

