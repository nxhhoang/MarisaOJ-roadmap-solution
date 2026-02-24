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

void solve()
{
    int n, arr, k;
    cin >> n >> k;
    int mod = 123456789;
    vector<int> pos(2002, -1);
    vector<vi> pref(n + 1, vi(k + 1, 0));
    vector<vi> dp(n + 1, vi(k + 1, 0));
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr;
        if (pos[arr] == -1) dp[i][1] = 1, pref[i][1] = 1, pos[arr] = 1;
        pref[i][1] += pref[i - 1][1];
        // cout << "[" << pref[i][1] << ", " << dp[i][1] << "] ";
        // cout << pos[arr] << " " << i << " ";
        for (int j = 2; j <= k; j++) {
            
            dp[i][j] = (pref[i - 1][j - 1] - pref[pos[arr] - 1][j - 1] + mod) % mod;
            pref[i][j] += (dp[i][j] + pref[i - 1][j]) % mod;
            // cout << "[" << pref[i][j] << ", " << dp[i][j] << "] ";
        }
        // cout << endl;
        pos[arr] = i;
    }
    cout << pref[n][k] << endl;
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
