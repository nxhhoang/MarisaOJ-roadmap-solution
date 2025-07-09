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

int vis[MAXSIZE], que[MAXSIZE], val[MAXSIZE], we[MAXSIZE], vl[MAXSIZE] = {0};
vector<vector<pii>> tre(MAXSIZE + 1);
multiset<int> st;
vector<int> vt;
int sqr;

ll query(int u, int v) {
    int a = u, b = v;
    int maxW = 1;
    while (val[u] < val[v] - sqr) maxW = max(maxW, vl[v]), v = que[v];
    while (val[v] < val[u] - sqr) maxW = max(maxW, vl[u]), u = que[u];
    while (val[u] < val[v]) maxW = max(maxW, we[v]), v = vis[v];
    while (val[v] < val[u]) maxW = max(maxW, we[u]), u = vis[u];
    while (que[u] != que[v]) maxW = max({maxW, vl[u], vl[v]}), u = que[u], v = que[v];
    while (u != v) maxW = max({maxW, we[u], we[v]}), u = vis[u], v = vis[v];
    
    return maxW;
}

void dfs(int u, int p) {
    vis[u] = p;
    for (int i = 0; i < tre[u].size(); i++) if (tre[u][i].first == p) we[u] = tre[u][i].second;
    for (int i = 0; i < tre[u].size(); i++ ) {
        int m = tre[u][i].first;
        if (m == p) continue;

        val[m] = val[u] + 1;
        vt.push_back(m);
        que[m] = vt[val[m] - 2];

        st.insert(tre[u][i].second);
        if (val[m] > sqr + 1) {
            auto it = st.find(we[que[m]]);
            if (it != st.end()) st.erase(it);
        }
        if (val[m] > sqr) vl[m] = *st.rbegin();
        dfs(m, u);
        
        if (val[m] > sqr + 1) st.insert(we[que[m]]);
        auto it = st.find(tre[u][i].second);
        if (it != st.end()) st.erase(it);

        vt.pop_back();
    }
}

void solve()
{
    int n, q, a, b; ll w;
    cin >> n >> q;
    sqr = sqrt(n);
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> w;

        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
    }

    vt.resize(sqr, 1);
    que[1] = 1;
    val[1] = 1;
    dfs(1, 1);

    while(q--) {
        cin >> a >> b;

        cout << query(a, b) << endl;
    }
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
