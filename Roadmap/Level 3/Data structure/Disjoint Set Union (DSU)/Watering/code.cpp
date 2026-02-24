// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe

// __builtin_popcount(x); - leftmost bit
// __builtin_parity(x); nums of 1 (even or odd)
// __builtin_ctz(x); count trailing zeros
// __builtin_clz(x); count leading zeros

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second
#define SIZE(x) (int)(x).size()

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MSIZE = 1e5 + 5;
const int MAXN = 2e7 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct tam {
    int a, b;
    int val;
};

const int N = 502;

int vec[N], st[N];
 
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
    int n;
    cin >> n;

    vector<tam> ed;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ed.push_back(tam{i, 0, a});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (i > j) ed.push_back(tam{i, j, a});
        }
    }

    sort(all(ed), [](tam l, tam r) -> bool {
        return l.val < r.val || (l.val == r.val && l.a < r.a);
    });

    for (int i = 0; i <= n; i++) make_set(i);

    ll sum = 0;
    for (int i = 0; i < SIZE(ed); i++) {
        auto [x, y, val] = ed[i];

        if (find_set(x) != find_set(y)) union_set(x, y), sum += val;
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout)
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

    while (t--)
    {
        solve();
    }
    return 0;
}
