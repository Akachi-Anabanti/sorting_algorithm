#include "sort.h"
#include <limits.h>


/**
 * max - returns the max value of an array of size size
 *
 * @array: The array
 * @size: The size of the array
 * Return: The maximum value
 */
int max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Counting sort algorithm
 *
 * @array: The input array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k, i;

	if (array == NULL || size < 2)
		return;
	k = max(array, size);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	/**assign the values of the array to zero**/
	for (i = 0; i < (k + 1); i++)
		count[i] = 0;
	/* assing the index value of count**/
	for (i = 0; i < (int)size; i++)
	{
		count[array[i]] += 1;
	}
	for (i = 0; i < (k + 1); i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; ++i)
		array[i] = output[i];
	free(count);
	free(output);
}
