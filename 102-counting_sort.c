#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: The array to be sorted.
 * @size:  The size of the array.
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *new_array;
	size_t i, j, max_val = 0;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
		max_val = ((size_t)array[i] > max_val) ? (size_t)array[i] : max_val;
	counting_array = malloc(sizeof(int) * (max_val + 1));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max_val; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	print_array(counting_array, max_val + 1);
	for (i = 1; i <= max_val; i++)
		counting_array[i] += counting_array[i - 1];
	new_array = malloc(sizeof(int) * size);
	if (new_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (j = size - 1; (int)j >= 0; j--)
	{
		i = counting_array[array[j]] - 1;
		new_array[i] = array[j];
		counting_array[array[j]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = new_array[i];
	free(counting_array);
	free(new_array);
}
