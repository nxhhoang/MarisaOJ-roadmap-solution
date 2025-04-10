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
    int n;
    cin >> n;
    vector<int> p(n);
    FOR(i, 0 , n) cin >> p[i];
    FOR(i , 0, n + 1) make_set(i);

    FOR(i, 0, n) {
        int val = find_set(p[i]);
        cout << val << " ";
        int val1 = val + 1;
        if (val1 == n + 1) val1 = 1;
        // union_set(val, val1);
        vec[val] = find_set(val1);
        st[val] += st[find_set(val1)];
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
