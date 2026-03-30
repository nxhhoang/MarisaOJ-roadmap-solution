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
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
vector<vector<pii>> tre(MAXN);
vector<vector<ll>> dp(MAXN, vector<ll>(3, LLONG_MAX / 2));
priority_queue<pll, vector<pll>, greater<pll>> pq;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m;i++) {
        int a, b ,w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    pq.push({0, 1});
    dp[1][0] = 0; dp[1][1] = dp[1][2] = 0;
    while (pq.size()) {
        auto [pa, ve] = pq.top();
        pq.pop();

        for (auto [v, w] : tre[ve]) {
            if (dp[v][0] > pa + w) {
                dp[v][0] = pa + w;
                dp[v][2] = min(pa, dp[v][2]); // 0 canh cuoi
                dp[v][1] = min({dp[v][1], dp[v][2], dp[ve][1] + w}); // duong di tot nhat mat 1 canh

                pq.push({dp[v][0], v});
            } else if (dp[v][2] > pa) {
                dp[v][2] = min(pa, dp[ve][0]);
                dp[v][1] = min({dp[v][2], dp[ve][1] + w, dp[v][1]});

                pq.push({dp[v][0], v});
            } else if (dp[v][1] > dp[ve][1] + w) {
                dp[v][1] = dp[ve][1] + w;
                
                pq.push({dp[v][0], v});    
            }
        }
    }

    if (dp[n][1] == LLONG_MAX / 2) cout << "-1";
    else cout << dp[n][1];
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
