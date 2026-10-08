FastTranspose
Sparse matrix fast transpose implemented in C++.
Triple table storage for sparse matrix.

Algorithm
- Pre-count the number of non-zero elements of each column.
- Calculate the starting position of each column in transposed triple table.
- Traverse original triple list once and place elements directly.

Complexity:
-Time: O(n + t)
    n: number of columns of original matrix
    t: number of non-zero elements
- Space: O(n) for auxiliary array num and pos


