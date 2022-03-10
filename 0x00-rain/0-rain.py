#!/usr/bin/env python3
"""Contains the function rain()"""


def rain(walls):
    """Calculates how much rainfall the walls will retain"""
    totalRain = 0
    spaces = 0
    prevWall = 0

    if not walls:
        return 0

    for wall in walls:
        if prevWall > 0 and wall == 0:
            spaces += 1
        if wall > 0 and spaces >= 1 and prevWall:
            totalRain += spaces * min(wall, prevWall)
            spaces = 0
        if wall > 0:
            prevWall = wall

    return totalRain
