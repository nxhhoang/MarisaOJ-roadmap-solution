// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int n;
    cin >> n;

    vector<int> iq(n + 1);
    vector<int> eq(n + 1);

    int maxV = 2;
    int am = 0;
    for (int i = 1; i <= n; i++) {
        cin >> iq[i] >> eq[i];
        if (iq[i] > 0) maxV += iq[i];
        else am -= iq[i];
    }

    maxV += am;
    vector<vi> dp(n + 1, vi(maxV, -MOD));
    dp[0][am] = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = min(maxV - iq[i], maxV - 1); j >= 0; j--) {
            if (j + iq[i] < maxV && j + iq[i] >= 0 && dp[i][j + iq[i]] <= dp[i - 1][j] + eq[i]) {
                dp[i][j + iq[i]] = dp[i - 1][j] + eq[i];
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int ans = 0;
    for (int i = am; i < maxV; i++) if (dp[n][i] >= 0) ans = max(ans, dp[n][i] + i - am);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
