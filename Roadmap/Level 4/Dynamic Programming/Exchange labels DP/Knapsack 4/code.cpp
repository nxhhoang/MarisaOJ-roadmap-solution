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

const int N = 502;

vector<ll> dp(N * N, LLONG_MAX / 100);
vector<ll> tmp(N * N, LLONG_MAX / 100);

void solve()
{
    int n, S;
    cin >> n >> S;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = v; j < N * N; j++) {
            if (dp[j - v] <= S - w) {
                tmp[j] = min(dp[j], dp[j - v] + w);
            }
        }
        for (int j = 0; j < N * N; j++) dp[j] = min(tmp[j], dp[j]);
        std::fill(all(tmp), LLONG_MAX / 100);
    }

    // for (int i = 0; i < 105; i++) cout << dp[i] << " ";
    // cout << endl; 

    ll pos = 0;
    for (int j = 0; j < N * N; j++) {
        if (dp[j] <= S) pos = j;
    }

    cout << pos << endl;
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
