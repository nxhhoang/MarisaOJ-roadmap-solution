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
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<vll> dp(n + 1, vll(n + 1, 0));

    bool ok = 1;
    if (n % 2) ok = 0; 
    for (int i = 1; i <= n; i++) cin >> arr[i], dp[i][i] = arr[i] * (ok == 1 ? 1 : -1);

    ok = !ok;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j + i <= n; j++) {
            if (ok == 1) dp[j][i + j] = max(dp[j + 1][i + j] + arr[j], dp[j][i + j - 1] + arr[i + j]);
            else dp[j][i + j] = min(dp[j + 1][i + j] - arr[j], dp[j][i + j - 1] - arr[i + j]);
        }

        ok = !ok;
    }

    cout << - dp[1][n] << endl;
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
