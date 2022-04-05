#!/usr/bin/python3
"""Containts the function rotate_2d_matrix()"""


def rotate_2d_matrix(matrix):
    """Rotates a 2d matrix by 90 degrees clockwise"""

    # Transpose matrix
    for i in range(len(matrix)):
        for j in range(i, len(matrix)):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse matrix
    for i in range(len(matrix)):
        matrix[i].reverse()
