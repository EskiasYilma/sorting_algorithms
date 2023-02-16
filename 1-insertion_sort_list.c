#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to listint_t head
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cur;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	while (cur != NULL)
	{
		listint_t *next = cur->next;

		while (cur->prev != NULL && cur->n < cur->prev->n)
		{
			listint_t *prev = cur->prev;

			prev->next = cur->next;

			if (cur->next != NULL)
				cur->next->prev = prev;

			cur->prev = prev->prev;
			cur->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = cur;

			prev->prev = cur;

			if (prev == *list)
				*list = cur;

			print_list(*list);
		}

		cur = next;
	}
}
