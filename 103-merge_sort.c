#include "sort.h"
/**
 * merger - performs the array merger and swap
 *
 * @arrA: The main array
 * @arrB: The dummy array use for working
 * @ibegin: The begining index of the array
 * @imid: The middle index of the array
 * @iend: The end index of the array
 */
void merger(int *arrA, int ibegin, int imid, int iend, int *arrB)
{
	int i = ibegin, j = imid, k;

	printf("Merging...\n[left]: ");
	print_array(arrA + ibegin, imid - ibegin);
	printf("[right]: ");
	print_array(arrA + imid, iend - imid);

	for (k = ibegin; k < iend; k++)
	{
		if (i < imid && (j >= iend || arrA[i] <= arrA[j]))
		{
			arrB[k] = arrA[i];
			i = i + 1;
		}
		else
		{
			arrB[k] = arrA[j];
			j = j + 1;
		}
	}
	printf("[Done] ");
	print_array(arrB + ibegin, iend - ibegin);
}
/**
 * td_split_merge - performs the top down array splitting
 *
 * @arrA: The main array
 * @arrB: The dummy array use for working
 * @ibegin: The begining index of the array
 * @iend: The end index of the array
 */
void td_split_merge(int *arrA, int ibegin, int iend, int *arrB)
{
	int imid;

	if (iend - ibegin < 2)
		return;
	imid = (iend + ibegin) / 2;
	td_split_merge(arrB, ibegin, imid, arrA);
	td_split_merge(arrB, imid, iend, arrA);
	merger(arrA, ibegin, imid, iend, arrB);
}
/**
 * merge_sort - Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *arrB = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		arrB[i] = array[i];
	td_split_merge(array, 0, size, arrB);
	free(arrB);
}
