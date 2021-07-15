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
    island_per = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if (grid[i][j] == 1):
                left = grid[i][j + 1]
                right = grid[i][j - 1]
                above = grid[i - 1][j]
                below = grid[i + 1][j]
                if (left + right + above + below == 2):
                    island_per += 2
                if (left + right + above + below == 1):
                    island_per += 3

    return island_per
