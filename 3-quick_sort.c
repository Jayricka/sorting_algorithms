/* 3-quick_sort.c */

#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps two integers in an array.
*
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* lomuto_partition - Lomuto partition scheme for Quick Sort.
*
* @array: Pointer to the array.
* @low: Starting index of the partition to be sorted.
* @high: Ending index of the partition to be sorted.
*
* Return: Index of the pivot's final position.
*/
int lomuto_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, high + 1);
}
}
}

if (i + 1 != high)
{
swap(&array[i + 1], &array[high]);
print_array(array, high + 1);
}

return (i + 1);
}

/**
* quick_sort_recursive - Recursive function to perform Quick Sort.
*
* @array: Pointer to the array.
* @low: Starting index of the partition to be sorted.
* @high: Ending index of the partition to be sorted.
*/
void quick_sort_recursive(int *array, int low, int high)
{
int pivot_idx;

if (low < high)
{
pivot_idx = lomuto_partition(array, low, high);
quick_sort_recursive(array, low, pivot_idx - 1);
quick_sort_recursive(array, pivot_idx + 1, high);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order using
*              the Quick Sort algorithm with Lomuto partition scheme.
*
* @array: Pointer to the first element of the array.
* @size: Number of elements in the array.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1);
}
