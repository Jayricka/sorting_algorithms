#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using insertion sort algorithm.
*
* @list: Double pointer to the head of the linked list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *insertion_point, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
insertion_point = current;
temp = current->prev;

while (temp != NULL && temp->n > insertion_point->n)
{
temp->next = insertion_point->next;
if (insertion_point->next != NULL)
insertion_point->next->prev = temp;

insertion_point->next = temp;
insertion_point->prev = temp->prev;
temp->prev = insertion_point;

if (insertion_point->prev != NULL)
insertion_point->prev->next = insertion_point;
else
*list = insertion_point;

print_list(*list);
temp = insertion_point->prev;
}

current = current->next;
}
}
