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
const int MAXSIZE = 1e5 + 5;
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

void solve() {
    int a, n, q;
    cin >> n >> q;
    vector<pii> sortt(n);
    vector<int> roirac(n);
    vector<pii> used(n);
    vector<int> value(n);

    FOR(i, 0, n) cin >> a, sortt[i] = {a, i};
    sort(all(sortt));
    FOR(i, 0, n) roirac[sortt[i].second] = i;
    FOR(i, 0, n) used[i] = {roirac[i], i}, make_set(i);
    sort(all(used));
    int maxV = 1;
    FOR(i, 0, n) {
        auto [x, y] = used[i];
        if (y != n - 1 && x >= roirac[y + 1]) union_set(x, roirac[y + 1]);
        if (y && x >= roirac[y - 1]) union_set(roirac[y - 1], x);
        sortt[i].second = (maxV = max(maxV, st[find_set(roirac[y])]));
    }
    pii cont;
    while(q--) {
        cin >> a;
        if (a < sortt[0].first) cout << 0 << endl;
        else {
            cont = {a, INT_MAX};
            auto it = upper_bound(all(sortt), cont);
            if (it != sortt.begin()) --it;
            cout << sortt[it - sortt.begin()].second << endl;            
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
