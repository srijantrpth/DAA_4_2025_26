# Time and Space Complexity

## Complexity Analysis

Let `n` be the length of string `s` and `m` be the length of string `t`.

### Time Complexity: `O(n * m)`

Each state in the memoization table is identified by a pair `(i, j)`, where `i` ranges over `s` and `j` ranges over `t`.
There are at most `n * m` such states, and each state is computed only once.
Since every computation does constant work besides the recursive calls, the total time complexity is `O(n * m)`.

### Space Complexity: `O(n * m)`

The DP table stores one value for each `(i, j)` state, so it uses `O(n * m)` space.
In addition, the recursion stack can grow as deep as `O(n + m)` in the worst case, but the dominant space usage is the memoization table.