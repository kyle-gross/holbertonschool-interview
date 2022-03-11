#!/usr/bin/python3
"""Contains the function rain()"""


def rain(walls):
    """Calculates how much rainfall the walls will retain"""
    if not walls:
        return 0

    totalRain = 0

    for i, h in enumerate(walls):
        leftTallest = max(walls[:i + 1])
        rightTallest = max(walls[i:])
        shorter = min(leftTallest, rightTallest)
        totalRain += max(shorter - h, 0)

    return totalRain
