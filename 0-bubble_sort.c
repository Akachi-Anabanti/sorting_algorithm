#include "sort.h"

/**
 * bubble_sort - Bubble sort alogrithm
 *
 *
 * @array: pointer to array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	int swapped;
	size_t old_size = size;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 1)
			print_array(array, old_size);
		size--;
	} while (swapped == 1);
}
