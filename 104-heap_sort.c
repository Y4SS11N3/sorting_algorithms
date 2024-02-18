#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Repairs the heap by moving the element at the given index down
 * to its proper position.
 * @array: An array of integers.
 * @start: The starting index of the heap.
 * @end: The ending index of the heap.
 * @size: The total size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
		{
			swap = child;
		}
		if (child + 1 <= end && array[swap] < array[child + 1])
		{
			swap = child + 1;
		}
		if (swap == root)
		{
			return;
		}
		else
		{
			swap_ints(&array[root], &array[swap]);
			print_array(array, size);
			root = swap;
		}
	}
}

/**
 * heapify - Creates a max heap from an unsorted array.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
	ssize_t start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using the sift-down
 * heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
	{
		return;
	}

	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		swap_ints(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}

