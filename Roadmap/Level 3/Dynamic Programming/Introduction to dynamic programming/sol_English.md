The knapsack problem can be solved using dynamic programming with the following key ideas:  

1. **Define the state:**  
   - Let `dp[i][w]` be the maximum value that can be obtained by selecting from the first `i` items with a total weight limit of `w`.  

2. **State transition formula:**  
   - If we don't take item `i`: `dp[i][w] = dp[i-1][w]`  
   - If we take item `i`: `dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i]] + value[i])`  

3. **Memory optimization:**  
   - Use a one-dimensional array `dp[w]`, updating it in reverse from `W` to `weight[i]` to avoid overwriting.  
