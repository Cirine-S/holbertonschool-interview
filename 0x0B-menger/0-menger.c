#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 *
 * @level: is the level of the Menger Sponge to draw
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void menger(int level)
{

	int i, j;
	int x, y;
	char d;

	if (level < 0)
		return;

	for (i = 0; i < pow(3, level); i++)
	{
		for (j = 0; j < pow(3, level);)
		{
			d = '#';
			x = i;
			y = j++;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					d = ' ';

				x /= 3;
				y /= 3;
			}
			putchar(d);
		}
		printf("\n");
	}

}
