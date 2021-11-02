#!/usr/bin/env python3
"""Contains the function canUnlockAll"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened

    Args:
        boxes: list of lists, contains integers

    Returns:
        True if all boxes can be opened, otherwise False
    """
    if not boxes:
        return False

    keys = [0]

    for i, box in enumerate(boxes):
        if i in keys:
            [keys.append(key) for key in box if key not in keys]
        else:
            for j in range(i, len(boxes)):
                if j in keys:
                    [keys.append(key) for key in boxes[j] if key not in keys]
            if i in keys:
                [keys.append(key) for key in box if key not in keys]
            else:
                return False

    return True
