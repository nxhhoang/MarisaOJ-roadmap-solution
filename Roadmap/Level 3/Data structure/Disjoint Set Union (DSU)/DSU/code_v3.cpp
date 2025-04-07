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
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<set<int>> vec(n + 1);
    vector<int> st(n + 1, 0);
    FOR(i, 1, n + 1) vec[i].insert(i), st[i] = i;

    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            int a = st[u];
            int b = st[v];
            if (a != b) {
                int mi, ma;
                if (vec[a].size() < vec[b].size()) mi = a, ma = b;
                else mi = b, ma = a;
                for (auto it = vec[mi].begin(); it != vec[mi].end(); ++it) vec[ma].insert(*it), st[*it] = ma;
                vec[mi].clear();
            }
        } else {
            if (st[u] == st[v]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
