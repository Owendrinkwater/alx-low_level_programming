#!/usr/bin/python3
"""Module that computes the perimeter of an island in a grid"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
    grid (list of list of int): 2D grid representing the island

    Returns:
    int: Perimeter of the island
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                # Check down
                if i + 1 < rows and grid[i + 1][j] == 1:
                    perimeter -= 2

                # Check right
                if j + 1 < cols and grid[i][j + 1] == 1:
                    perimeter -= 2

    return perimeter

