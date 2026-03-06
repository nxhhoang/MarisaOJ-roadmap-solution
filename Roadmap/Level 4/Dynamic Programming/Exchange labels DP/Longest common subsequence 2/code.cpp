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

const int MSIZE = 2e5 + 5;
const int MAXN = 2e7 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

const int N = 5002;

vector<vi> dp(N, vi(N, INT_MAX));
vector<vi> pos(26);

void solve()
{
    string s, t;
    cin >> s >> t;

    int n = SIZE(s);
    int m = SIZE(t);

    s = '#' + s;
    t = '#' + t;

    for (int i = 1; i <= n; i++) pos[s[i] - 'a'].push_back(i);
    
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            auto it = ub(all(pos[t[i] - 'a']), dp[i - 1][j - 1]);
            if (it != pos[t[i] - 'a'].end()) dp[i][j] = min(dp[i][j], *it);
        }
        for (int j = 0; j <= m; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         if (dp[i][j] == INT_MAX) dp[i][j] = -1;
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll maxV = 0;
    for (int i = 0; i <= m; i++) if (dp[m][i] <= max(n, m) && dp[m][i] >= i) maxV = i;
    cout << maxV << endl; 
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
