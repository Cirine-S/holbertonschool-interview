#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "palindrome.h"

/**
 * is_palindrome - checks whether or not "n" is a palindrome
 *
 * @n: integer to check
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char buffer[50];
	int i, len;

	sprintf(buffer, "%lu", n);
	len = strlen(buffer);

	for (i = 0; i < len; i++)
	{
		if (buffer[i] != buffer[len - i - 1])
			return (0);
	}
	return (1);
}
