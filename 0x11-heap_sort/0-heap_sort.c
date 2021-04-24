#include <stdlib.h>
#include <stdio.h>
#include "sort.h"


/**
 * swap - swap function
 * @a: pointer to element to swap
 * @b: pointer to element to swap
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - heapify function
 *
 * @array: The array to heapify
 * @n: Number of elements in @array
 * @i: index
 */
void heapify(int array[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}
}

/**
 * heap_sort - main function to do heap sort
 *
 * @array: The array to sort
 * @n: Number of elements in @array
 */
void heap_sort(int *array, size_t n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(array, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, n);
		heapify(array, i, 0);
	}
}
