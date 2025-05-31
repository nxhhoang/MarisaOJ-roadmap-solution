# Idea

* To check for a **palindrome**, we compare the left and right parts of a string to see if they are equal.

* The problem requires us to **add the minimum number of characters** to make the input string a palindrome. So clearly, we need to find the **longest possible palindrome** already present in the string (the characters don't need to be contiguous).

* A longest palindrome has two symmetric parts (left and right) that are equal and as long as possible. Therefore, this problem can be **reduced to finding the longest common subsequence (LCS)** between two parts of the string. This is known as the **Longest Common Subsequence** problem. (See: [https://marisaoj.com/problem/144](https://marisaoj.com/problem/144))

* Let's define the pairs we need to check (with \$n\$ being the length of the input string):

  * For **even-length palindromes**, we split the string at position \$t\$ and compare \$S\[1 \rightarrow t]\$ with \$S\[(t + 1) \rightarrow n]\$ for all \$t \in \[1, n - 1]\$. There are \$n - 1\$ such pairs.
  * For **odd-length palindromes**, we split around a center character \$S\[t+1]\$ and compare \$S\[1 \rightarrow t]\$ with \$S\[(t + 2) \rightarrow n]\$ for all \$t \in \[1, n - 2]\$. There are \$n - 2\$ such pairs.
  * For convenience, the second half of the pair is reversed before comparing. For example, for string `"abcdef"`, a possible even pair is `"abc"` and `"fed"`, and an odd pair is `"ab"` and `"fed"` with `"c"` as the center.

* We'll iterate through all **odd** and **even** pairs. The current algorithm for computing the LCS of two strings `a` and `b` runs in \$O(mn)\$, where \$m\$ is the length of `a` and \$n\$ is the length of `b`. If we apply this to all pairs, the total complexity becomes:

  $$
  \sum_{x = 1}^{n - 1} x(n - x) + \sum_{x = 1}^{n - 2} x(n - x)
  $$

* With \$n\$ up to 1000, the total number of operations exceeds \$3 \times 10^8\$, which is expensive.

* We can reduce the time by processing each **even pair** while simultaneously also considering the **odd pair**.

* For example, with input `S = abcdefg`, to find the common subsequence between `a` and `gfedcb` (an even pair), we would compare `a` with each character in `gfedcb`. Note that comparing `a` with `gfedc` (i.e., excluding the last character) is equivalent to processing an odd pair. Thus, for each even pair, we can reuse the same comparison process for the corresponding odd pair (except the last even pair where the right side has length 1).

---

# Accepted (AC) Code

<details>
<summary>VIEW CODE</summary>

```cpp
// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    vector<int> dp(S.size(), 0);
    int ans = S.size();
    int n = S.size();

    string fo="";
    string ba=S;
    reverse(all(ba));
    for (int i = 0; i < S.size(); i++){
        for (int j = 0; j < fo.size(); j++) {
            int val = 0;
            for (int k = 0; k < ba.size(); k++) {
                if (ba[k] == fo[j]) {
                    if (val + 1 > dp[k]) {
                        dp[k] = val + 1;
                    } else val = dp[k];
                } else val = max(dp[k], val);
            }
            for (int k = 0; k < ba.size(); k++) {
                if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]);
                else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
            }
        }
        std::fill(all(dp), 0);
        ba.pop_back();
        fo.push_back(S[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

</details>

---

# Improved Algorithm Idea

* The author uses the `dp` array to store the length of the longest common subsequence ending at each position in the reversed half. It helps track and update values for the second half of each even or odd pair.
* However, the above method is still inefficient, since the overall complexity remains > \$1e8\$.
* Notice that from one pair to the next, only **one character** shifts from the right half to the left half. For example, if the input is `"abcdefgh"`, an even pair may be `"abcd"` and `"hgfe"`, and the next pair is `"abcde"` and `"hgf"`.
* The left halves share a common prefix (`"abcd"`), and the right halves share a common prefix in reverse (`"hgf"`). So instead of recomputing LCS from scratch, we can update `dp` in a **rolling** manner using reverse iteration, without clearing and recalculating it fully.

---

# Optimized Code

<details>
<summary>VIEW CODE</summary>

```cpp
// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    string S;
    cin >> S;
    vector<int> dp(S.size(), 0);
    int ans = S.size();
    int n = S.size();

    string fo = S.substr(0, 1);
    string ba = S.substr(1);
    reverse(all(ba));
    for (int i = 1; i < S.size(); i++){
        if ((n - ans) / 2 > ba.size() || (n - ans) / 2 > fo.size()) break;
        int val = 0;
        for (int k = 0; k < ba.size(); k++) {
            if (ba[k] == fo[i - 1] && val + 1 > dp[k]) {
                dp[k] = val + 1;
                continue;
            } 
            if (val <= dp[k]) val = dp[k];
        }
        for (int k = 0; k < ba.size(); k++) {
            if (k == ba.size() - 1) ans = min(ans, n - 2 * dp[k]);
            else if (k == ba.size() - 2) ans = min(ans, n - 2 * dp[k] - 1);
        }
        ba.pop_back();
        fo.push_back(S[i]);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
```

</details>
