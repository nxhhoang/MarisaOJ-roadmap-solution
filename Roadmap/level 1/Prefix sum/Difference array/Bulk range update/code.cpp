#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> adj(n + 2);
    vector<int> q_adj(q + 2);
    vector<pair<int,int>> qqq(q);

    FOR(i, 0, q) cin >> qqq[i].first >> qqq[i].second;

    while(m--){
        int x, y;
        cin >> x >> y;
        q_adj[x]++;
        q_adj[y + 1]--;
    }

    FOR(i, 1, q + 1) {
        q_adj[i] += q_adj[i - 1];
        adj[qqq[i - 1].first] += q_adj[i];
        adj[qqq[i - 1].second + 1] -= q_adj[i];
    }

    FOR(i, 1, n + 1) {
        cout << (adj[i] += adj[i - 1]) << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
