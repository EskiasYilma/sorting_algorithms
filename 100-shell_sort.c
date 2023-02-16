#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: Pointer to array
 * @size: size of array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t sp = 1, i, j;
	int temp;

	while (sp < size / 3)
		sp = sp * 3 + 1;

	while (sp > 0) {
		for (i = sp; i < size; i++) {
			temp = array[i];
			for (j = i; j >= sp && array[j - sp] > temp; j -= sp) {
				array[j] = array[j - sp];
			}
			array[j] = temp;
		}
		sp /= 3;

		printf("%d", array[0]);
		for (i = 1; i < size; i++) {
			printf(", %d", array[i]);
		}
		printf("\n");
	}
}
