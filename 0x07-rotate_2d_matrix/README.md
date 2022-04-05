# Rotate Matrix

In this task we rotate a `n` x `n` matrix 90 degrees clockwise. I solved this by transposing the matrix then reversing each row.

Time complexity: `O(n*n)` where `n` is the size of the matrix.

Space complexity: `O(1)`

To run:
```
./0-main.py
```

Example input:
```
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

rotate_2d_matrix(matrix)
print(matrix)
```
Output:
```
[[7, 4, 1],
[8, 5, 2],
[9, 6, 3]]
```