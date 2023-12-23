#include "sort.h"

/**
 * swap - swaps two array indexes
 *
 * @a: the first value
 * @b: the second value
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - performs the list partition
 *
 * @array: The array to partition
 * @low: the low index
 * @high: The high index
 * @size: size of the array
 *
 * Return: Position of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * sorter - recursively performs the sorting
 *
 * @array: The array to sort
 * @low: The low index
 * @high: The high index
 * @size: The size of the array
 *
 */
void sorter(int *array, int low, int high, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array, low, high, size);
		sorter(array, low, part - 1, size);
		sorter(array, part + 1, high, size);
	}
}

/**
 * quick_sort - Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	sorter(array, 0, size - 1, size);
}
