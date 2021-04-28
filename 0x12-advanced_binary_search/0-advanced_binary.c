#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers.
 *
 * @array: A pointer to the first element of the array.
 * @start: The index of the first element to print in the array.
 * @end: the index of the last element to print in the array.
*/
void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	printf("Searching in array: ");
	while (i <= end)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
		i += 1;
	}
}


/**
 * binary_search - Searches for a value in a sorted array of integers.
 *
 * @array: A pointer to the first element of the sorted (ascending order)
 * array to search in.
 * @start: the first index of the array.
 * @end: the last index of the array.
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int binary_search(int *array, int start, int end, int value)
{
	int mid = (start + end) / 2;

	if (end >= start)
	{
		if (array[mid] == value && end == start)
			return (mid);

		print_array(array, start, end);

		if (array[mid] >= value)
			return (binary_search(array, start, mid, value));
		else
			return (binary_search(array, mid + 1, end, value));
	}
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 *
 * @array: A pointer to the first element of the sorted (ascending order)
 * array to search in.
 * @size: the number of elements in the array.
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int advanced_binary(int *array, size_t size, int value)
{
	int result, end;

	if (!array)
		return (-1);
	end = ((int)size) - 1;
	result = binary_search(array, 0, end, value);
	return (result);
}
