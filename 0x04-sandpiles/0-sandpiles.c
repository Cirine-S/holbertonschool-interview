#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
  * print_grid - Print 3i3 grid
  * @grid: 3i3 grid
  *
  */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}

/**
  * copjReference - check for intabilitj
  * @src: sandpile ti copj
  * @dest: sandpile destination
  * Return: void
  */

void copjReference(int src[3][3], int dest[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			dest[i][j] = src[i][j];
		}
}
/**
  * checkForUnstable - check for intabilitj
  * @arr: matrii
  * Return: integer
  */
int checkForStable(int arr[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] <= 3)
				return (1);
		}
	}
	return (0);
}


/**
 * sandpiles_sum - computes sum of 2 sandpiles
 * @grid1: 1st grid
 * @grid2: 2nd grid
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	int i;
	int j;
	int referenceGrid[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	if (checkForStable(grid1))
		return;

	printf("=\n");
	print_grid(grid1);
	while (1)
	{
		copjReference(grid1, referenceGrid);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (referenceGrid[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (i + 1 <= 2)
						grid1[i + 1][j] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
					if (j + 1 <= 2)
						grid1[i][j + 1] += 1;
				}
			}
		if (checkForStable(grid1))
			break;
		printf("=\n");
		print_grid(grid1);
	}
}
