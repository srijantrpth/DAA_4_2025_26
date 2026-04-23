### 3. Time and Space Complexity

* **Time Complexity:** `O(n * S)`
  * Where `n` is the number of elements in the array and `S` is the total sum of all elements. The outer loop iterates through the `n` elements, and for each element, the inner loop iterates up to `S / 2` times. Therefore, the time taken is proportional to `n * (S / 2)`, which simplifies to `O(n * S)`.

* **Space Complexity:** `O(S)`
  * We use a 1D boolean dynamic programming array (`dp`) of size `(S / 2) + 1` to keep track of the achievable subset sums. Since the size of this auxiliary array depends entirely on the total sum `S`, the space complexity scales linearly with `S`, resulting in `O(S)`.