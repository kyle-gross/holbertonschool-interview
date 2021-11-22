#!/usr/bin/python3
"""Contains the function minOperations()"""


def minOperations(n):
    """Determines how many operations are required to Copy-All->Paste to
    achieve `n` number of characters in a text file. Starting from 1 character

    Returns:
        ops (int): minimum operations required to copy and paste to achieve
        `n` operations.
            * if `n` is impossible to achieve, returns 0
    """
    ops = 0
    i = 2

    while (i <= n):
        # See if problem can be broken into smaller problems
        while (n % i == 0):
            # If yes then add no of smaller problems to result
            ops += i
            # Create smaller problem
            n = n / i
        # Iterator
        i += 1

    return ops
