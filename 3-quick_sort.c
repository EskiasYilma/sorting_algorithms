#include "sort.h"

#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two elements
 * @a: element a pointer
 * @b: element b pointer
 * Return: Nothing
 */

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * lamuto_partition - Lomuto partition
 * @ar: Pointer to array
 * @low: start index
 * @high: end index
 * @size: size of array
 * Return: index of the pivot element
 */

int lamuto_partition(int *ar, int low, int high, size_t size)
{
	int pivot = ar[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (ar[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&ar[i], &ar[j]);
				print_array(ar, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&ar[i + 1], &ar[high]);
		print_array(ar, size);
	}

	return (i + 1);
}

/**
 * sort_partition - sort lamuto_partition of array
 * @array: Pointer to array
 * @low: partition start index
 * @high: partition end index
 * @size: size of array
 * Return: Nothing
 */

void sort_partition(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lamuto_partition(array, low, high, size);

		sort_partition(array, low, p - 1, size);
		sort_partition(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: Pointer to array
 * @size: size of array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
	{
		sort_partition(array, 0, size - 1, size);
	}
}
