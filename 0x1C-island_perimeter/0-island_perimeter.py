#!/usr/bin/python3
"""
island perimeter module
"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid

    Args:
        grid ([matrix of 0 and 1s]): representing water and land

    Returns:
        [integer]: perimeter of the found island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if (grid[i][j]):
                perimeter += 4
                if (grid[i - 1][j] and i > 0):
                    perimeter -= 2
                if (grid[i][j - 1] and j > 0):
                    perimeter -= 2
    return perimeter
