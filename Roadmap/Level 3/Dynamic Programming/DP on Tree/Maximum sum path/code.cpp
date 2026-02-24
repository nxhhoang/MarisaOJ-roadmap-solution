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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
vector<ll> va(MAXSIZE);
vector<ll> cur(MAXSIZE, 0);
vector<vi> tre(MAXSIZE);
ll rel;

void dfs(int u, int p) {
    for (int i = 0; i < tre[u].size() ; i++) {
        int m = tre[u][i];
        if (p == m) continue;
        dfs(m, u);
    }
    ll val1 = LLONG_MIN / 3;
    ll val2 = LLONG_MIN / 3;
    int pos = 0;
    int cnt = 0;
    cur[u] = max(va[u], cur[u]);
    for (int i = 0; i < tre[u].size(); i++) {
        int m = tre[u][i];
        if (p == m) continue;
        bool ok = 1;
        cnt++;
        if (val1 < cur[m]) val2 = val1, val1 = cur[m], ok = 0;
        if (ok) val2 = max(val2, cur[m]);
        cur[u] = max({cur[u], cur[m] + va[u]});
        // rel = max({rel, cur[u] + })
    }
    rel = max({cur[u], rel});
    if (cnt >= 2) rel = max({val2 + val1 + va[u], rel});
    // cout << u <<  " " << rel << endl;
}

void solve()
{
    cin >> n ;
    int a, b;
    for (int i = 1; i <= n; i++) cin >> va[i];
    for (int i = 0 ; i < n - 1; i++) {
        cin >> a>> b;
        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    
    dfs(1, 1);
    cout << rel << endl;
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
