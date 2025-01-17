### Ý tưởng
- Để giải quyết bài toán đếm số mảng con mà tổng XOR của chúng có số bit 1 lẻ, ta cần phân tích các tính chất liên quan đến tính chẵn lẻ số bit 1 trong biểu diễn nhị phân. Dựa trên các tính chất này, ta xây dựng giải thuật để giải quyết bài toán hiệu quả.
- Ta có tính chẵn lẻ bit 1 của một tổng `XOR` sẽ có mối quan hệ đến tính chẵn lẻ của từng phần tử trong mảng con.
- Ta sẽ xét hai số bất kì `a` và `b`. Và `c` là kết quả của `a XOR b`.
- Biểu diễn `a` và `b` dưới dạng nhị phân.
- Gọi x là số cặp mà bit 1 của `a` tương ứng với bit 1 của `b` ở vị trí `k` trong biểu diễn nhị phân.
- Gọi y là số cặp mà bit 1 của `a` tương ứng với bit 0 của `b` ở vị trí `k` trong biểu diễn nhị phân.
- Gọi z là số cặp mà bit 0 của `a` tương ứng với bit 1 của `b` ở vị trí `k` trong biểu diễn nhị phân.
- Số bit 1 của `a` khi đó là `x + y`.
- Số bit 1 của `b` khi đó là `x + z`.
- Số bit 1 của `c` khi đó là `y + z`.

#### TH1: số bit 1 của `a` và `b` cùng lẻ.
- Vì `a` lẻ nên `x + y` lẻ tương tự `x + z` lẻ, suy ra `x + y + x + z` chẵn.
- Suy ra `2x + y + z` chẵn, bỏ đi `2x` thì `y + z` chẵn, hay ta có số bit 1 của `c` là chẵn.

#### TH2: số bit 1 của `a` và `b` cùng chẵn.
- Vì `a` chẵn nên `x + y` chẵn tương tự `x + z` chẵn, suy ra `x + y + x + z` chẵn.
- Suy ra `2x + y + z` chẵn, bỏ đi `2x` thì `y + z` chẵn, hay ta có số bit 1 của `c` là chẵn.

#### TH3: số bit 1 của `a` lẻ và của `b` chẵn.
- Vì `a` lẻ nên `x + y` lẻ còn `b` chẵn thì `x + z` chẵn, suy ra `x + y + x + z` lẻ.
- Suy ra `2x + y + z` lẻ, bỏ đi `2x` thì `y + z` lẻ, hay ta có số bit 1 của `c` là lẻ.

#### TH4: số bit 1 của `a` chẵn và của `b` lẻ.
- Vì `a` lẻ nên `x + y` lẻ còn `b` lẻ thì `x + z` chẵn, suy ra `x + y + x + z` lẻ.
- Suy ra `2x + y + z` lẻ, bỏ đi `2x` thì `y + z` lẻ, hay ta có số bit 1 của `c` là lẻ.

Ta nhận thấy tính chẵn lẻ số bit 1 sau khi `XOR` hoạt động giống tính chẵn lẻ của hai số nguyên cộng lại.

### Code mẫu 1 C++
```cpp
// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pll pair<ll, ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() { 
    int n;
    ll sum = 0;
    cin >> n;
    vector<int> arr(n);
    vector<pll> dp(n + 1);
    FOR(i, 0, n) cin >> arr[i], arr[i] = __builtin_popcount(arr[i]) % 2; 
    FOR(i, 0, n) {
        if (arr[i]) dp[i + 1].first = dp[i].second + 1, dp[i + 1].second = dp[i].first;
        else dp[i + 1].first = dp[i].first, dp[i + 1].second = dp[i].second + 1;
        sum += dp[i + 1].first;
    }
    cout << sum;
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
### Tối ưu về không gian cho đoạn code
Ta nhận thấy ở mỗi thời điểm, ta chỉ quan tâm tới một số nên ta có thể tối ưu bằng cách giảm từ mảng xuống 1 số, và thay mảng `dp` thành các biến `M`, `N` để lưu trạng thái ở thời điểm đó.

```cpp
// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pll pair<ll, ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() { 
    int n, a;
    ll sum = 0, M = 0, N = 0;
    cin >> n;
    FOR(i, 0, n) {
        cin >> a;
        a = __builtin_popcount(a) % 2;
        (a) ? swap(M, N), M++ : N++;
        sum += M;
    }
    cout << sum;
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
