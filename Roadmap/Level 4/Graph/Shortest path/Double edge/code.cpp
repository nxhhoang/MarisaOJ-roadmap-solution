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
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
vector<vector<pii>> ol(MAXN);
vector<vector<pii>> ne(MAXN);
vector<int> cnt(MAXN, INT_MAX);
vector<bool> check(MAXN, 0);
vector<int> dp(MAXN, 1000000);
priority_queue<pii, vector<pii>, greater<pii>> q;

void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        ol[a].push_back({b, w});
        ol[b].push_back({a, w});
    }
}

void solve()
{   
    init();
    for (int i = 1; i <= n; i++) {
        for (auto ve : ol[i]) {
            if (check[ve.first]) continue;
            check[ve.first] = 1;
            for (auto u : ol[ve.first]) {
                if (u.first == i) continue;
                if (cnt[u.first] == INT_MAX) {
                    cnt[u.first] = u.second * ve.second;
                    ne[i].push_back({u.first, cnt[u.first]});
                }
                if (cnt[u.first] > u.second * ve.second) {
                    cnt[u.first] = u.second * ve.second;
                }
            }
        }
        for (auto ve : ol[i]) check[ve.first] = 0;
        for (auto &ve : ne[i]) {
            ve.second = cnt[ve.first];
            if (i == 1) dp[ve.first] = ve.second, q.push({dp[ve.first], ve.first});
            cnt[ve.first] = INT_MAX;
        }
    }

    q.push({0, 1});
    dp[1] = 0;

    while (q.size()) {
        auto [pa, ve] = q.top();
        q.pop();

        if (pa > dp[ve]) continue;
        dp[ve] = pa;
        for (auto [v, w] : ne[ve]) {
            if (dp[v] > w + pa) {
                dp[v] = w + pa;
                q.push({dp[v], v});
            }
        }
    }

    if (dp[n] == 1000000) cout << -1;
    else cout << dp[n];
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
