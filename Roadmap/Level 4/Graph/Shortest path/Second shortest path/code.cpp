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
const int MSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
vector<vector<pii>> tre(MSIZE);
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<vector<ll>> dp(MSIZE, vector<ll>(2, INT_MAX));

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    pq.push({0, 1});
    dp[1][0] = dp[1][1] = 0;
    while (pq.size()) {
        auto [pa, ve] = pq.top();
        pq.pop();

        if (dp[ve][0] < pa) {
            if (dp[ve][1] == dp[ve][0] || dp[ve][1] >= pa) dp[ve][1] = pa;
            else continue;
        }

        for (auto [v, w] : tre[ve]) {
            if (dp[v][0] > pa + w) {
                dp[v][1] = dp[v][0];
                dp[v][0] = pa + w;
                pq.push({dp[v][0], v});
                pq.push({dp[v][1], v});
            } else if (dp[v][1] == dp[v][0] || dp[v][1] > pa + w) {
                dp[v][1] = pa + w;
                // cout << w << " " << dp[v][1] << " " << dp[v][0] << " " <<  v << " " << ve << endl;
                if (dp[v][1] != dp[v][0]) pq.push({dp[v][1], v});
            }
            if (dp[v][1] > dp[ve][0] + w && dp[v][0] < dp[ve][0] + w) {
                dp[v][1] = dp[ve][0] + w;
                pq.push({dp[v][1], v});
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << "     "<< dp[i][0] << " " << dp[i][1] << endl;
    // }

    cout << dp[n][1];
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
