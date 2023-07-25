#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !(*list) || !((*list)->next))
		return;

	listint_t *current, *insertion_point, *temp;

	current = (*list)->next;
	while (current)
	{
		insertion_point = current->prev;
		temp = current;
		current = current->next;

		while (insertion_point && insertion_point->n > temp->n)
		{
			if (insertion_point->prev)
				insertion_point->prev->next = temp;
			if (temp->next)
				temp->next->prev = insertion_point;
			insertion_point->next = temp->next;
			temp->prev = insertion_point->prev;
			temp->next = insertion_point;
			insertion_point->prev = temp;

			if (!temp->prev)
				*list = temp;

			print_list(*list);
			insertion_point = temp->prev;
		}
	}
}
