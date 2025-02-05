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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int dp[2][MAXSIZE];

void solve() {
    int n, S, w, u;
    cin >> n >> S;
    int maxV = 0;
    FOR(i, 0, n) {
        cin >> w >> u;
        dp[1][w] = u;
        FOR(j, 0, S) {
            if (i) {
                dp[1][j] = max(dp[1][j], dp[0][j]);
                if (j + w <= S) 
                    dp[1][j + w] = max(dp[1][j + w], dp[0][j] + u);
            } 
            maxV = max(dp[1][j], maxV);
            dp[0][j] = dp[1][j];
        }
    }
    cout << maxV << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
