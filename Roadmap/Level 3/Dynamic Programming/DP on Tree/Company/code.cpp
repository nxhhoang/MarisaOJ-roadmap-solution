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
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};



const int N = 501;
int n, L;
vector<vi> tre(N);
vector<int> s(N);
vector<vi> uv(N, vi(N));
vector<vll> dp(N, vll(N, INT_MIN));

void dfs(int u, int p) {
    for (int j = 0; j <= s[u]; j++) {
        dp[u][j] = uv[u][j];
    }

    for (int ve : tre[u]) {
        if (ve == p) continue;
        dfs(ve, u);

        vll tmp = dp[u];
        for (int j = 0; j <= s[u]; j++) {
            for (int k = 0; k <= s[ve]; k++) {
                if (j + k <= s[u]) {
                    tmp[j + k] = max(tmp[j + k], dp[u][j] + dp[ve][k]);
                }
            }
        }
        dp[u] = tmp;
    }
}

void solve()
{
    cin >> n >> L;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tre[x].push_back(i);
        tre[i].push_back(x);
    }

    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= L; j++) cin >> uv[i][j];
        dp[i][0] = 0;
    }

    dfs(1, 0);

    ll maxV = 0;
    for (int i = 0; i <= s[1]; i++) maxV = max(maxV, dp[1][i]);

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
