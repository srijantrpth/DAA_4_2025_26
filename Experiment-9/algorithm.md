### Algorithm: Minimum Sum Partition

1. **Calculate Total Sum:** Compute the total sum `S` of all elements in the given array.
2. **Define the Target:** The goal is to find a subset whose sum is as close to `S / 2` as possible. If we find a subset with sum `j`, the other subset will have a sum of `S - j`. The difference will be `S - 2j`.
3. **Initialize DP Array:** Create a 1D boolean dynamic programming array `dp` of size `(S / 2) + 1`. Initialize all elements to `false`, except `dp[0]` which is set to `true` (since a sum of 0 is always possible with an empty subset).
4. **Process Each Element:** Iterate through each element `arr[i]` in the given array.
5. **Update Subset Sums:** For each element, iterate backwards from the target sum `S / 2` down to the value of the current element `arr[i]`.
6. **State Transition:** Update the `dp` array using the relation: `dp[j] = dp[j] || dp[j - arr[i]]`. This essentially means a sum `j` is possible if it was already possible without the current element, or if the sum `j - arr[i]` was possible.
7. **Find Optimal Sum:** After processing all elements, iterate backwards from `S / 2` to `0` to find the largest index `j` such that `dp[j]` is `true`. This `j` represents the largest subset sum that is less than or equal to `S / 2`.
8. **Calculate Minimum Difference:** Return the minimum absolute difference between the two subsets, which is calculated as `S - 2 * j`.