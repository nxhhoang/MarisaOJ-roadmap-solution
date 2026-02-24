// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
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

int n;
vector<vi> tre(MSIZE);
vector<int> l(MSIZE, 0);
vector<int> r(MSIZE, 0);
vector<vector<ll>> dp(MSIZE, vector<ll>(2, 0));

void dfs(int u, int p) {
    for (int ve : tre[u]) {
        if (ve == p) continue;
        dfs(ve, u);
        dp[u][1] += max(dp[ve][1] + abs(r[u] - r[ve]), dp[ve][0] + abs(r[u] - l[ve]));
        dp[u][0] += max(dp[ve][1] + abs(l[u] - r[ve]), dp[ve][0] + abs(l[u] - l[ve]));
    }
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }

    dfs(1, 0);

    cout << max(dp[1][1], dp[1][0]) << endl;
    for (int i = 1; i <= n; i++) while (tre[i].size()) tre[i].pop_back();
    for (int i = 1; i <= n; i++) l[i] = 0, r[i] = 0, dp[i][0] = dp[i][1] = 0;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
