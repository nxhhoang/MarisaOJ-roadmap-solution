#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int N = 10;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> arr(n, vector<ll>(m));
    vector<vector<ll>> preSum2D(n + 1, vector<ll>(m + 1, 0));

    FOR(i, 0, n)
    FOR(j, 0, m)
    {
        cin >> arr[i][j];
        preSum2D[i + 1][j + 1] = arr[i][j] + preSum2D[i][j + 1] + preSum2D[i + 1][j] - preSum2D[i][j];
    }

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll sum = preSum2D[c][d] - preSum2D[a - 1][d] - preSum2D[c][b - 1] + preSum2D[a - 1][b - 1];
        cout << sum << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
