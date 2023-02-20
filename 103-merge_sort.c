#include "sort.h"

/**
 * merge - Merge two subarrays of array[].
 * @array: Array containing the subarrays.
 * @lsize: Size of the Right subarrays.
 * @rsize: Size of the Left subarrays.
 * @left: Left subarray.
 * @right: Right subarray.
 * Return: Nothing
 */
void merge(int *array, int *left, size_t lsize, int *right, size_t rsize)
{
	size_t i = 0, j = 0, k = 0;
	int *merged = malloc(sizeof(int) * (lsize + rsize));

	printf("Merging...\n[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
	print_array(right, rsize);

	while (i < lsize && j < rsize)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < lsize)
		merged[k++] = left[i++];

	while (j < rsize)
		merged[k++] = right[j++];

	for (i = 0; i < lsize + rsize; i++)
		array[i] = merged[i];

	free(merged);
}


/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * merge sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, lsize, rsize;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;
	lsize = mid;
	rsize = size - mid;

	merge_sort(left, lsize);
	merge_sort(right, rsize);

	merge(array, left, lsize, right, rsize);
	printf("[Done]: ");
	print_array(array, size);
}
