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

void solve() {
    string S;
    cin >> S;
    int n = S.size();
    vector<vi> dp(n, vi(n));
    dp[1][0] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (S[i + 1] == '?') {
                if (j > 0 && dp[j][i] > 0) dp[j - 1][i + 1] = (dp[j - 1][i + 1] + dp[j][i]) % MOD;
                if (j < n - 1) dp[j + 1][i + 1] = (dp[j + 1][i + 1] + dp[j][i]) % MOD;
            } else if (S[i + 1] == ')' && j > 0) dp[j - 1][i + 1] = dp[j][i];
            else if (j < n - 1) dp[j + 1][i + 1] = dp[j][i];
            // cout << dp[j][i] << " ";
        }
        // cout << endl;
    }
    cout << dp[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; LLLLLLLLLLLLLLLLLLLLL
    while(t--){
        solve();
    }
    return 0;
}

// (())()
// ((()))
// (()())
