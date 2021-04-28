#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"


/**
 * print_array - Prints an array of integers.
 *
 * @array: A pointer to the first element of the array.
 * @start: The index of the first element to print in the array.
 * @end: the index of the last element to print in the array.
*/
void print_array(int *array, size_t l, size_t r)
{

	printf("Searching in array: ");
	for (size_t i = l; i <= r; i++)
	{
		printf("%d", array[i]);
		if (i != r)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - Searches for a value in a sorted array of integers.
 *
 * @array: A pointer to the first element of the sorted (ascending order)
 * array to search in
 * @l: the first index of the array
 * @r: the last index of the array
 * @value: the value to search for
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int binary_search(int *array, int l, int r, int value)
{
	int m = (r + l) / 2;

	if (r >= l)
	{
		if (array[m] == value && l == r)
			return m;
		print_array(array, l, r);
		if (array[m] >= value)
			return binary_search(array, l, m, value);
		if (array[m] < value)
			return binary_search(array, m+1, r, value);

	}
	return (-1);
	
}
/**
 * advanced_binary -  searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int l = 0;
	int r = size - 1;
	int result;

	if (!array) 
		return (-1);
	
	result = binary_search(array, l, r, value);
	return result;
	
}
