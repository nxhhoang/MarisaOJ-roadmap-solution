Bài toán knapsack có thể giải bằng quy hoạch động với ý tưởng chính:  

1. **Xác định trạng thái:**  
   - Gọi `dp[i][w]` là giá trị lớn nhất có thể đạt được khi chọn từ `i` vật phẩm đầu tiên với tổng trọng lượng tối đa `w`.  

2. **Công thức chuyển:**  
   - Nếu không chọn vật phẩm thứ `i`: `dp[i][w] = dp[i-1][w]`  
   - Nếu chọn vật phẩm thứ `i`: `dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i]] + value[i])`  

3. **Tối ưu bộ nhớ:**  
   - Dùng mảng một chiều `dp[w]`, cập nhật ngược từ `W` về `weight[i]` để tránh ghi đè.  
