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

const int MSIZE = 1e5 + 5;
const int MAXN = 2e7 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
vector<vi> tre(MSIZE);
vector<int> arr(MSIZE);
vector<vll> dp(MSIZE, vll(2, 0));

void dfs(int u, int p) {
    for (auto ve : tre[u]) {
        if (ve == p) continue;
        dfs(ve, u);
        dp[u][0] = max(dp[u][0], dp[ve][0]);
        dp[u][1] = max(dp[u][1], dp[ve][1]);
    }

    arr[u] += (dp[u][1] - dp[u][0]);
    if (arr[u] > 0) dp[u][0] += arr[u];
    else dp[u][1] -= arr[u];
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tre[a].push_back(b);
        tre[b].push_back(a);
    }

    dfs(1, 0);
    
    cout << dp[1][0] + dp[1][1] << endl;
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
