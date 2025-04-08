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

int vec[MAXSIZE], st[MAXSIZE], tongg[MAXSIZE];

int find_set(int u) {
    return (vec[u] == u) ? u : (vec[u] = find_set(vec[u]));
}

void union_set(int u, int v) {
    int a = find_set(u);
    int b = find_set(v);
    if (a != b) {
        if (st[a] > st[b]) swap(a, b);
        vec[a] = b;
        st[b] += st[a];
        tongg[b] += tongg[a];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
    FOR(i, 1, n + 1) vec[i] = i, st[i] = 1, tongg[i] = i;
    while (q--) {
        int t, u, v;
        cin >> t >> u;
        if (t == 1) cin >> v, union_set(u, v);
        else cout << tongg[find_set(u)] << endl;
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
