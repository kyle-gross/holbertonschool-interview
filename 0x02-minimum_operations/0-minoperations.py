#!/usr/bin/python3
"""Contains the function minOperations()"""


def minOperations(n):
    """Determines how many operations are required to Copy-All->Paste to
    achieve `n` number of characters in a text file. Starting from 1 character

    Returns:
        min_op (int): minimum operations required to copy and paste to achieve
        `n` operations.
            * if `n` is impossible to achieve, returns 0
    """
    for i in range(n):
        i += i
        if i == n:
            return i
    return 0
