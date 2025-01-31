#include <bits/stdc++.h>
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

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    FOR(i, 0, n) FOR(j, 0, m)
    {
        char c;
        cin >> c;
        pre[i + 1][j + 1] = c - '0' + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
    }
    ll ans = 0;

    FOR(i, 0, n)
    FOR(j, i + 1, n + 1)
    {
        int a = 1, b = 1;
        while (b <= m)
        {
            while (a < b && (pre[j][b] - pre[i][b]) - (pre[j][a - 1] - pre[i][a - 1]) > k)
                a++;
            if ((pre[j][b] - pre[i][b]) - (pre[j][a - 1] - pre[i][a - 1]) <= k)
                ans = max(ans, (j - i) * 1ll * (b - a + 1));
            b++;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
