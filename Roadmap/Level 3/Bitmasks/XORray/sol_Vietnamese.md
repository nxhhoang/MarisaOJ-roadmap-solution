### Ý tưởng
- Ta quy ước $\oplus$ là phép `XOR`, $+$ là phép `OR` và $.$ là phép `AND`.
- Xét $n$ phần tử $A_1, A_2, A_3,..., A_n$.
- Ta lập bảng như sau, với các tổng `OR` ở cột phần tử $A_i$ bắt đầu lần lượt từ ${1, 2,..., i - 1, i}$ và kết thúc tại $i$. Đây cũng chính là số tổng cần có để tính tổng `XOR`.

| Phần tử $A_1$ | Phần tử $A_2$ | Phần tử $A_3$ | ... | Phần tử $A_n$|
|:-------------:|:-------------:|:-------------:|:---:|:------------:|
| $f(1, 1)$     | $f(1, 2)$     | $f(1, 3)$     | ... | $f(1, n)$    |
|               | $f(2, 2)$     | $f(2, 3)$     | ... | $f(2, n)$    |
|               |               | $f(3, 3)$     | ... | $f(3, n)$    |
|               |               |               | ... |      ...     |
|               |               |               | ... | $f(n, n)$    |
| _____________ | _____________ | _____________ | ___ | ____________ |
| $F(1, 1)$     | $F(1, 2)$     | $F(1, 3)$     | ... | $F(1, n)$    |

- Ta định nghĩa $F(1, k)$ là tổng `XOR` của các tổng `OR` kết thúc tại $k$.
- Vậy yêu cầu của bài toán trở thành: Tính tổng `XOR` của các tổng $F(1, k)$ với $k \in {1,2,...,n}$.
- Ta có: $F(1, 1) = f(1, 1) = A_1$.
- Tiếp tục: $F(1, 2) = f(1, 2) \oplus f(2, 2) = (A_1 + A_2) \oplus (A_2) = A_1.\overline{A_2}$.
- Tiếp tục: $F(1, 3) = f(1, 3) \oplus f(2, 3) \oplus f(3, 3) = (A_1 + A_2 + A_3) \oplus (A_2 + A_3) \oplus (A_3) = A_1.\overline{A_2} + A_3$.
- Tiếp tục: $F(1, 4) = (A_1.\overline{A_2} + A_3).\overline{A_4}$.

- Bằng phép quy nạp dễ dàng xây dựng được công thức truy hồi như sau:
$$ 
F(1, n) = 
\begin{cases} 
A_1, &\text{if } n == 1 \newline
F(1, n - 1) + A_n, & \text{if } n\text{ is odd} \newline 
F(1, n - 1).\overline{A_n} , & \text{if } n\text{ is even} 
\end{cases} 
$$
$$
F(1, n) = 
\begin{cases} 
A_1, & \text{if } n == 1 \newline
F(1, n - 1) + A_n, & \text{if } n \text{ is odd} \newline
F(1, n - 1).\overline{A_n}, & \text{if } n \text{ is even}
\end{cases}
$$

### Code C++
```cpp
// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve(){
    int n, a, result = 0, cur = 0;
	cin >> n;
    FOR (i, 1, n + 1) {
        cin >> a;
        if (i % 2) cur |= a;
        else cur &= ~a;
        result ^= cur;
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
```
