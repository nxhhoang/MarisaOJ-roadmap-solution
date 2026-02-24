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
    int n, S;
    cin >> n >> S;

    vector<ll> w(n + 1);
    vector<ll> v(n + 1);
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> a[i];

    vector<int> bi2((int)log2(2e4), 1);
    for (int i = 1; i < SIZE(bi2); i++) bi2[i] = bi2[i - 1] * 2;

    vector<ll> res(S + 1, 0);
    vector<ll> dp(S + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> pie;
        for (int j = 0; j < SIZE(bi2); j++) {
            if (a[i] >= bi2[j]) {
                pie.push_back(bi2[j]);
                a[i] -= bi2[j];
            } else break;
        }
        if (a[i] > 0) pie.push_back(a[i]);
        
        for (int j = 0; j < SIZE(pie); j++) {
            int nw = pie[j] * w[i];
            int nv = pie[j] * v[i];
            for (int k = nw; k <= S; k++) res[k] = max(res[k], dp[k - nw] + nv);
            for (int k = 0; k <= S; k++) dp[k] = max(res[k], dp[k]);
        }
    }

    ll maxV = 0;
    for (int i = 0; i <= S; i++) maxV = max(maxV, dp[i]);
    
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
