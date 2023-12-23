#include "sort.h"

/**
 * shell_sort - shell sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size == 0)
		return;
	gap = 0;
	while (gap < size)
		gap = gap * 3 + 1;
	gap = gap / 3;
	/*returns the gap to previous value before loop exit*/
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
