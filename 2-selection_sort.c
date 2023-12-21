#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	int temp, swapped;

	for (i = 0; i < size - 1; i++)
	{
		jMin = i;
		swapped = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
				continue;
			}
		}
		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			swapped = 1;
		}
		if (swapped == 1)
		{
			print_array(array, size);
		}
	}
}
