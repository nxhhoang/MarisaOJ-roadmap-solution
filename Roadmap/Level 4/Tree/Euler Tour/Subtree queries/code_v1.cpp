// nxhhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
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

vector<vi> tre(MAXSIZE);
vector<ll> cnt(MAXSIZE, 0);
vector<ll> tmp(MAXSIZE, 0);
ll sum = 0;

void dfs(int u, int p) {
    sum += cnt[u];
    tmp[u] = sum;
    for (int i = 0; i < tre[u].size(); i++ ) {
        int m = tre[u][i];
        if (m == p) continue;
        dfs(m, u);
    }
    sum -= cnt[u];
}

void solve()
{
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    while(q--) {
        cin >> a >> b;
        cnt[a] += b;
    }
    dfs(1, 1);
    for (int i = 1; i <= n; i++) cout << tmp[i] << ' ';
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
