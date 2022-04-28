#!/usr/bin/python3
"""Contains the function makeChange()"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest no.
    coins needed to meet a given amount.

    Args:
      coins (list): contains integers representing the value of coins
      total (int): the total you must make given the coins list
        * must be > 0

    Returns:
      * integer representing the fewest no. coins needed to meet total
      * -1 if it is not possible
    """
    if total <= 0:
        return 0

    # Sort coins with the largest denominations at the front of the list
    coins.sort(reverse=True)
    count = 0

    # Iterate through coin list while subtracting from total
    # Count the number of times subtraction is performed to sum the
    # total number of coins required
    for coin in coins:
        while total - coin >= 0 and coin <= total:
            total -= coin
            count += 1

    # If total is not 0, then it's not possible
    if total != 0:
        return -1

    return count


if __name__ == '__main__':
    print(makeChange([1, 2, 25], 37))

    print(makeChange([1256, 54, 48, 16, 102], 1453))
