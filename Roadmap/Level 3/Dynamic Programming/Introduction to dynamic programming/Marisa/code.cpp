// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    string s;
    cin >> s;
    int dp[6] = {0};
    for (auto c : s) {
        if (c == 'm') dp[0]++;
        else if (c == 'a') dp[1] = (dp[1] + dp[0]) % MOD, dp[5] = (dp[5] + dp[4]) % MOD;
        else if (c == 'r') dp[2] = (dp[2] + dp[1]) % MOD;
        else if (c == 'i') dp[3] = (dp[3] + dp[2]) % MOD;
        else if (c == 's') dp[4] = (dp[4] + dp[3]) % MOD;
    }
    cout << dp[5] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
