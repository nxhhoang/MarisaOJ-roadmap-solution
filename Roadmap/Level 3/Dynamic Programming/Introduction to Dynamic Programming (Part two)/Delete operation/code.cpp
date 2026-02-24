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

const int MaxSize = 5001;

int n, k;
vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(MaxSize, vector<ll>(2, 0)));
vector<int> arr(MaxSize);
vector<ll> preF(MaxSize, 0);

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        preF[i] = preF[i - 1] + arr[i];
    }

    ll maxV = preF[n];
    for (int i = 1; i <= n; i++) {
        dp[1][0][0] = preF[i];
        dp[1][0][1] = preF[i];
        dp[0][0][0] = preF[i - 1];
        dp[0][0][1] = preF[i - 1];
        for (int j = 1; j <= k; j++) {
            dp[1][j][0] = max({dp[0][j - 1][1], dp[0][j][0]});
            dp[1][j][1] = max({dp[0][j][0] + arr[i], dp[0][j][1] + arr[i]});
        }
        if (i == n) break;
        for (int j = 1; j <= k; j++) {
            dp[0][j][0] = dp[1][j][0];
            dp[0][j][1] = dp[1][j][1];
        }
    }
    for (int j = 0; j <= k; j++) maxV = max({dp[1][j][0], dp[1][j][1], maxV});
    cout << maxV << endl;
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
