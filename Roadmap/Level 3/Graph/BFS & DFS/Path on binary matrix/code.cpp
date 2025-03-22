// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> st(n);
    vector<vi> dp(n, vi(m, MOD));
    queue<pii> q;

    for (int i = 0; i < n; i++) cin >> st[i];

    q.push({0, 0});
    dp[0][0] = 0;
    while(q.size()) {
        auto [x, y] = q.front();
        for (int i = 0; i < 4; i++) {
            int a = dx[i] + x;
            int b = dy[i] + y;
            if (a < 0 || b < 0 || a >= n || b >= m || dp[a][b] != MOD || st[a][b] == '1') continue;
            q.push({a, b});
            dp[a][b] = min(dp[x][y] + 1, dp[a][b]);
        }
        q.pop();
    }

    if (dp[n - 1][m - 1] == MOD) cout << -1 << endl;
    else cout << dp[n - 1][m - 1] << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
