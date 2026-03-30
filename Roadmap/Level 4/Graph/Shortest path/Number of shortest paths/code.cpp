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
vector<vector<pii>> tre(MAXN);
vector<ll> val(MAXN, LLONG_MAX / 4);
vector<ll> cnt(MAXN, 0);

void solve()
{   
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    cnt[1] = 1;
    val[1] = 0;

    while (pq.size()) {
        auto [pa, ve] = pq.top();
        pq.pop();
        // cout << pa << " " << ve << endl;

        if (val[ve] < pa) continue;
        for (auto &[v, w] : tre[ve]) {
            if (val[v] == pa + w) {
                cnt[v] = (cnt[v] + cnt[ve]) % MOD;
                // pq.push({val[v], v});
            }
            if (val[v] > pa + w) {
                val[v] = pa + w;
                // cout << pa << "   " << w << "   " << v << endl;
                cnt[v] = cnt[ve];
                pq.push({val[v], v});
            }
        }
    }
    cout << cnt[n];
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
