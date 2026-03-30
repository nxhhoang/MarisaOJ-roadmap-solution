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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> tre(n + 1);
    vector<ll> pa(n + 1, -1);
    vector<ll> val(n + 1, INT_MAX);
    val[1] = 0;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;

        tre[u].push_back({v,w});
        tre[v].push_back({u,w});
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    while(pq.size()){
        auto [w, u] = pq.top();
        pq.pop();

        if (val[u] < w) continue;

        for (int i = 0; i < tre[u].size(); i++){
            int d = tre[u][i].first;
            int we = tre[u][i].second;
            if (val[d] == INT_MAX || val[d] > val[u] + we) {
                pa[d] = u;
                val[d] = val[u] + we;
                pq.push({val[d], d});
            }
        }
    }
    
    if (pa[n] == -1) {
        cout << -1 << endl;
        return;
    }
    cout << val[n] << endl;
    stack<int> st;
    int v = n;
    while(v != 1) {
        st.push(v);
        v = pa[v];
    }
    cout << 1 << " ";
    while(st.size()) cout << st.top() << " ", st.pop();
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
