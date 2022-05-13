#!/usr/bin/python3
"""
Finds the perimeter
of an island
The island is surrounded by water
Water is wet
"""

def island_perimeter(grid):
    """
    Let's find the perimeter of an island!
    The island is surrounded by water
    """

    # Null check
    if grid is None:
        return 0

    perim = 0
    row_len = len(grid)
    col_len = len(grid[0])

    # Verify that grid is right size
    if row_len > 100 or col_len > 100:
        return 0

    # Loop through grid and look around when 1's are encountered
    # If there's 0's or matrix edge around a 1, perimeter increases
    try:
        for row in range(row_len):
            for col in range(col_len):
                if grid[row][col] == 1:
                    if grid[row - 1][col] == 0:
                        perim += 1
                    if grid[row + 1][col] == 0:
                        perim += 1
                    if grid[row][col - 1] == 0:
                        perim += 1
                    if grid[row][col + 1] == 0:
                        perim += 1
    except IndexError:
        continue
    return perim
