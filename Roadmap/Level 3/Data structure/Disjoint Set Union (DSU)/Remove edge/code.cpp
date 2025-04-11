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

int vec[MAXSIZE], st[MAXSIZE];

void make_set(int u) {
    vec[u] = u;
    st[u] = 1;
}

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
    }
}

bool check(int u, int v) {
    return find_set(u) == find_set(v);
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> vec(m);
    vector<pair<int, int>> que(q);
    vector<int> vis(m, 0);
    stack<int> stt;
    for(int i = 0; i < m; i++) cin >> vec[i].first >> vec[i].second;
    for(int i = q - 1; i >= 0; i--) cin >> que[i].first >> que[i].second, vis[que[i].first - 1] = 1;
    FOR(i, 1, n + 1) make_set(i);
    for(int i = 0; i < m; i++) if (vis[i] == 0) union_set(vec[i].first, vec[i].second); 

    for (int i = 0; i < q; i++) {
        int t = que[i].first;
        stt.push(st[find_set(que[i].second)]);
        union_set(vec[t - 1].first, vec[t - 1].second);
    }

    while(stt.size()) cout << stt.top() << endl, stt.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
