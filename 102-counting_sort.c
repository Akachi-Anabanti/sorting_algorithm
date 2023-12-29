#include "sort.h"
#include <limits.h>
/**
 * counting_sort - Counting sort algorithm
 *
 * @array: The input array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k = INT_MIN, min = INT_MAX;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
		if (array[i] < min)
			min = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] -= min;
	k -= min;
	count = malloc(sizeof(int) * (k + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;
	for (i = 0; i < (size_t)k + 1; i++)
		count[i] = 0;
	for (j = 0; j < size; ++j)
	{
		++count[array[j]];
	}
	for (i = 1; i <= (size_t)k; ++i)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	for (i = 0; i < size; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}
	for (i = 0; i < size; ++i)
		array[i] = output[i];
	for (i = 0; i < size; ++i)
		array[i] += min;
	free(count);
	free(output);
}
