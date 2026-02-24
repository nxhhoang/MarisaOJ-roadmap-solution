// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)

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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
vector<vi> tre(MSIZE);
vector<int> dp(MSIZE, 1);
ll sum = 0;

void dfs(int u, int p) {
    for (int i = 0; i < tre[u].size(); i++) {
        int m = tre[u][i];
        if (p == m) continue;
        dfs(m, u);
        dp[u] = (1ll * dp[u] * (dp[m] + 1)) % MOD;
    }
    sum = (sum + dp[u]) % MOD;
}

void solve()
{
    int a, b;
    cin >> n;    
    for (int i = 0; i < n - 1;i++) {
        cin >> a >> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    dfs(1, 1);
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
