#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps the values of an array at the given indeces.
 *
 * @array: the array to swap its elements.
 * @index_one: the index of the first element.
 * @index_two: the index of the second element.
*/
void swap(int *array, int index_one, int index_two)
{
	int tmp;

	tmp = array[index_one];
	array[index_one] = array[index_two];
	array[index_two] = tmp;
}

/**
 * max_heapify - Convert a Heap into a max heap.
 *
 * @array: the array representation of the heap to max-heapify.
 * @size: the number of nodes in the heap.
 * @index: the index to heapify.
*/
void max_heapify(int *array, int size, int index)
{
	int largest, left, right;

	right = 2 * index + 2;
	left = 2 * index + 1;
	largest = index;

	if (left <= size && array[left] > array[index])
		largest = left;
	if (right <= size && array[right] > array[largest])
		largest = right;
	if (largest != index)
	{
		swap(array, largest, index);
		print_array(array, size);
		max_heapify(array, size, largest);
	}
}

/**
 * sift_down - Repair the heap whose root element is at index start.
 *
 * @array: the array of the elements.
 * @size: the size of the array.
 * @start: the first index of the heap.
 * @end: the last index of the heap.
*/
void sift_down(int *array, int size, int start, int end)
{
	int change, child, root, left, right;

	root = start;

	while (((2 * root) + 1) <= end)
	{
		left = 2 * root + 1;
		child = left;
		change = root;

		if (array[change] < array[child])
			change = child;
		right = 2 * root + 2;
		if (right <= end && array[change] < array[right])
			change = right;
		if (change != root)
		{
			swap(array, root, change);
			print_array(array, size);
			root = change;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array in the sift-down Heap sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the length of the array.
*/
void heap_sort(int *array, size_t size)
{
	int i, end, array_size;

	if (size <= 1)
		return;
	array_size = ((int) size);
	i = array_size - 1;

	for (; i >= 0; i--)
		max_heapify(array, array_size, i);

	end = array_size - 1;

	while (end > 0)
	{
		swap(array, 0, end);
		print_array(array, size);
		end = end - 1;
		sift_down(array, ((int) array_size), 0, end);
	}
}
