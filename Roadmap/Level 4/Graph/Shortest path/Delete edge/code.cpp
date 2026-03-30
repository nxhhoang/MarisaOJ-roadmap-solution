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

int n, m, k;
vector<vector<pii>> tre(MAXN);
vector<ll> val(MAXN, LLONG_MAX/4);

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq[k + 2];

    for (int i = 0; i <= k; i++) {
        pq[i].push({0, 1});
        val[1] = 0;

        while (pq[i].size()) {
            auto [pa, ve] = pq[i].top();
            pq[i].pop();

            if (pa > val[ve]) continue;
            val[ve] = pa;
            for (auto &v : tre[ve]) {
                if (val[v.first] >= pa + v.second) {
                    val[v.first] = pa + v.second;
                    pq[i].push({val[v.first], v.first});
                    pq[i + 1].push({pa, v.first});
                } else if (val[v.first] > pa) {
                    pq[i + 1].push({pa, v.first});
                }
            }
        }
    }
    if (val[n] == LLONG_MAX/4) cout << -1;
    else cout << val[n];
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
