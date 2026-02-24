// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe

// __builtin_popcount(x); - leftmost bit
// __builtin_parity(x); nums of 1 (even or odd)
// __builtin_ctz(x); count trailing zeros
// __builtin_clz(x); count leading zeros

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second
#define SIZE(x) (int)(x).size()

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    string s;
    cin >> s;

    
    int n = SIZE(s);
    s = '#' + s;
    

    vector<vi> dp(n + 1, vi(n + 1, INT_MAX / 10));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;

    // for (int i = 1; i <= n - 1; i++) {
    //     for (int j = 1; i + j <= n; j++) {
    //         // dp[j][j + i] = min(dp[j][j + i], dp[j][j + i - 1] + (s[i + j] != s[j + i - 1]));
    //         // dp[j][j + i] = min(dp[j][j + i], dp[j][j + i - 1] + (s[i + j] != s[j]));

    //         // dp[j][j + i] = min(dp[j][j + i], dp[j + 1][j + i] + (s[j] != s[j + i]));
    //         // dp[j][j + i] = min(dp[j][j + i], dp[j + 1][j + i] + (s[j] != s[j + 1]));
        
    //         if (s[j] == s[j + i]) {
    //             dp[i][i + j] = min(dp[i + 1][i + j], dp[i][i + j - 1]);
    //         } else {
    //             for (int k = i; k < i + j; k++) {
    //                 dp[i][i + j] = min(dp[i][k] + dp[k + 1][i + j], dp[i][i + j]);
    //             }
    //         }
    //     }   
    // }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;

            if (s[l] == s[r]) {
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
            } else {
                for (int k = l; k < r; k++) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }

    cout << dp[1][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout)
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

    while (t--)
    {
        solve();
    }
    return 0;
}
