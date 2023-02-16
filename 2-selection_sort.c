#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Pointer to array
 * @size: size of array
 * Return: Nothing
 **/

void selection_sort(int *array, size_t size)
{
	size_t i, j, m_index;
	int t;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		m_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_index])
				m_index = j;
		}
		if (m_index != i)
		{
			t = array[i];
			array[i] = array[m_index];
			array[m_index] = t;
			print_array(array, size);
		}
	}
}
