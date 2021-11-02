# Lockboxes

This is an exercise in which there are `n` boxes, each labeled sequentially from `0` to `n - 1`. The label of each box corresponds to its index position in the list `boxes`. Each box contains keys (integers), which unlock other boxes.

These guidlines are observed:
* `boxes` is a list of lists
* A key with the same number as a box opens that box
* It is assumed that all keys are positive integers
    * Some keys do not have boxes
* The first box, `boxes[0]` is unlocked
* Return `True` if all boxes can be opened, otherwise return `False`

The program, `0-lockboxes.py`, determines if EVERY box in the list can be unlocked.
