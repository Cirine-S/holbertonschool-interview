#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: str
 * @pattern: pattern
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int i = 0, j = 0;
	(void)pattern;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.' || str[i] == '*')
			return (0);
	}

	i = 0;
	while (str[i] && pattern[j])
	{
		if (pattern[j] == '.' && pattern[j + 1] == '*' && !pattern[j + 2])
		{
			printf("here");
			return (1);
		}
		else if (str[i] == pattern[j] || pattern[i] == '.')
		{
			i++;
			j++;
		}
		else if (pattern[j] == '*' && str[i - 1] == pattern[j - 1])
		{
				while (str[i] == str[i - 1])
				{
				i++;
			}
		}
		else if (str[i] != pattern[j])
		{
			if (pattern[j + 1] == '*')
			{
				j += 2;
				printf("%c, %c ", str[i], pattern[j]);
			}
			else
			{
				return (0);
			}
		}
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}
