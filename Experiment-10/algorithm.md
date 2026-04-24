# Distinct Subsequences

## Algorithm

The goal is to count how many subsequences of string `s` are equal to string `t`.

We use recursion with memoization:

1. Start with two indices, `i` for `s` and `j` for `t`.
2. If `j` reaches the end of `t`, we found one valid subsequence, so return `1`.
3. If `i` reaches the end of `s` before `t` is fully matched, return `0`.
4. For each state `(i, j)`, there are two choices:
   - Skip `s[i]` and move to `(i + 1, j)`.
   - If `s[i] == t[j]`, match both characters and move to `(i + 1, j + 1)`.
5. Store the result for each `(i, j)` in a DP table so the same subproblem is not solved twice.

This approach counts every valid way to form `t` from `s` while avoiding repeated work.