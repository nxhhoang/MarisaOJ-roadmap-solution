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
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


const int NN = 1e3 + 3;
vector<vector<pii>> tre(NN);
vector<vi> mt(NN, vi(NN, INT_MAX / 3));
vector<pii> ed;
vector<int> p(NN);
vector<int> dis(NN, INT_MAX/3);
int n, m, k, a, b;

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        tre[a].push_back({b, 1});
        tre[b].push_back({a, 1});
        ed.push_back({a, b});
        mt[a][b] = 1;
        mt[b][a] = 1;
    }
    
    queue<int> q; 
    for (int i = 0; i < k; i++) {
        int ii = p[i];
        dis[ii] = 0;
        q.push(ii);
        while(q.size()) {
            auto tp = q.front();
            q.pop();
            for (int j = 0; j < tre[tp].size(); j++) {
                auto [vl, el] = tre[tp][j];
                if (dis[vl] > dis[tp] + el) 
                    dis[vl] = dis[tp] + el, q.push(vl);
            }
        }
        for (int j = 1; j <= n; j++) mt[ii][j] = mt[j][ii] = min(mt[ii][j], dis[j]);
        std::fill(all(dis), INT_MAX/3);
    }
    
    ll ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        ll sum = 0;
        for (int j = 0; j < k; j++) {
            sum += min(mt[ed[i].first][p[j]], mt[ed[i].second][p[j]]);
        }
        ans = min(ans, sum);
    }
    cout << ans;
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
