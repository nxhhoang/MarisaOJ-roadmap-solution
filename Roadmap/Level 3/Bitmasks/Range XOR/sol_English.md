### Idea
- To solve the problem of counting subarrays where the XOR sum has an odd number of `1` bits, we analyze the properties related to the parity of `1` bits in binary representation. Based on these properties, we construct an efficient algorithm to solve the problem.
- The parity of the `1` bits in a `XOR` sum is related to the parity of each element in the subarray.
- Let us consider two numbers `a` and `b`, and let `c` be the result of `a XOR b`.
- Represent `a` and `b` in binary.
- Let `x` be the number of pairs where the `1` bit of `a` corresponds to the `1` bit of `b` at position `k` in the binary representation.
- Let `y` be the number of pairs where the `1` bit of `a` corresponds to the `0` bit of `b` at position `k`.
- Let `z` be the number of pairs where the `0` bit of `a` corresponds to the `1` bit of `b` at position `k`.
- The number of `1` bits in `a` is `x + y`.
- The number of `1` bits in `b` is `x + z`.
- The number of `1` bits in `c` is `y + z`. We have `1 XOR 1 = 0`, `1 XOR 0 = 1` và `0 XOR 1 = 1` then the results of `x` pairs are 0, while those `y` và `z` pairs are 1.

#### Case 1: The number of `1` bits in both `a` and `b` is odd.
- Since `a` is odd, `x + y` is odd. Similarly, `x + z` is odd, which implies `x + y + x + z` is even.
- Thus, `2x + y + z` is even. Subtracting `2x` gives `y + z` as even, meaning the number of `1` bits in `c` is even.

#### Case 2: The number of `1` bits in both `a` and `b` is even.
- Since `a` is even, `x + y` is even. Similarly, `x + z` is even, which implies `x + y + x + z` is even.
- Thus, `2x + y + z` is even. Subtracting `2x` gives `y + z` as even, meaning the number of `1` bits in `c` is even.

#### Case 3: The number of `1` bits in `a` is odd, and in `b` is even.
- Since `a` is odd, `x + y` is odd. Since `b` is even, `x + z` is even, which implies `x + y + x + z` is odd.
- Thus, `2x + y + z` is odd. Subtracting `2x` gives `y + z` as odd, meaning the number of `1` bits in `c` is odd.

#### Case 4: The number of `1` bits in `a` is even, and in `b` is odd.
- Since `a` is even, `x + y` is even. Since `b` is odd, `x + z` is odd, which implies `x + y + x + z` is odd.
- Thus, `2x + y + z` is odd. Subtracting `2x` gives `y + z` as odd, meaning the number of `1` bits in `c` is odd.

We observe that the parity of the number of `1` bits after `XOR` behaves like the parity of adding two integers.

### Code Example 1 in C++
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

### Optimizing Space in the Code
We notice that at any moment, we are only concerned with one number. Therefore, we can reduce the space from an array to a single number, replacing the `dp` array with variables `M` and `N` to store the state at that time.

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
