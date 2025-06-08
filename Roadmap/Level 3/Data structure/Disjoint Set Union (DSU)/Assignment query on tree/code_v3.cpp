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
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int vec[MAXSIZE];
 
void make_set(int u) {
    vec[u] = u;
}
 
int find_set(int u) {
    return (vec[u] == u) ? u : (vec[u] = find_set(vec[u]));
}
 
void union_set(int u, int v) {
    int a = find_set(u);
    int b = find_set(v);
    if (a != b) {
        vec[a] = b;
    }
}
 
bool check(int u, int v) {
    return find_set(u) == find_set(v);
}

int n;
vector<vi> tre(MAXSIZE);
int col[MAXSIZE] = {0};
int bac[MAXSIZE] = {0};

void dfs(int dinh, int p) {
    for (int i = 0; i < tre[dinh].size(); i++) {
        int m = tre[dinh][i];
        if (m == p) continue;
        bac[m] = bac[dinh] + 1;
        dfs(m, dinh);
    }
}

void updfs(int dinh, int p, int tar, int color) {
    if (bac[dinh] < bac[tar]) return;
    if (dinh == tar) {
        if (col[dinh] == 0) col[dinh] = color;
        return;
    }
    int k = find_set(dinh);
    if (k != dinh) {
        updfs(k, dinh, tar, color);
        return;
    }
    if (col[dinh] == 0) col[dinh] = color;

    for (int i =0; i < tre[dinh].size(); i++){
        int m = tre[dinh][i];
        if (m == p || bac[dinh] < bac[m]) continue;
        union_set(dinh, m);
        if (col[m] == 0) col[m] = color;
        if (m == tar) return;
        updfs(find_set(m), dinh, tar, color);
    }
}

void solve()
{
    int q;
    cin >> n >> q;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    for (int i = 0; i <= n; i++) make_set(i);
    bac[1] = 1;
    dfs(1, 1);

    int x, y, z;
    while(q--){
        cin >> x >> y >> z;
        updfs(y, y, x, z);
    }
    for (int i = 1; i <= n; i ++) cout << col[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
