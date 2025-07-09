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
#define vll vector<ll>
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
vector<vi> cnt(MAXSIZE, vi(102, 0));
vector<vi> tmp(MAXSIZE, vi(102, 0));
int n, k, a, b;

void dfs(int u, int p) {
    for (int i = 0; i < tre[u].size(); i++ ) {
        int m = tre[u][i];
        if (m == p) continue;
        dfs(m, u);
        for (int j = 1; j < k; j++) {
            cnt[u][j + 1] += cnt[m][j];
            tmp[u][k] -= cnt[m][j] * cnt[m][k - j - 1];
            tmp[u][j] += cnt[m][j];
        }
        cnt[u][k] += cnt[m][k];
    }
    for (int i = 1; i < k; i++) tmp[u][k] += tmp[u][i] * tmp[u][k - i - 1];

    cnt[u][k] += tmp[u][k] / 2;
}

void solve()
{
    cin >> n >> k;
    k++;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        tre[a].push_back(b);
        tre[b].push_back(a);
    }
    
    for (int i = 0; i < n + 1; i++) cnt[i][1] = 1;
    dfs(1, 1);
    cout << cnt[1][k];
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
