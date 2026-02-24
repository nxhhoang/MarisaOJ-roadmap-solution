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
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
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
        // if (st[a] > st[b]) swap(a, b);
        vec[a] = b;
        st[b] += st[a];
    }
}

bool check(int u, int v) {
    return find_set(u) == find_set(v);
}

void solve()
{
    int n, q, d, a, b, u, v;
    cin >> n >> q;
    set<pii> st;
    for (int i = 0; i <= n; i++) make_set(i);
    while(q--) {
        cin >> d >> a >> b;
        u = find_set(a);
        v = find_set(b);

        if (d == 1) {
            auto itu = st.lb(make_pair(u, 0));
            auto itv = st.lb(make_pair(v, 0));
            // cout << itu->first << itu->second << endl;

            if (itu != st.end() && itu->first == u) union_set(b, itu->second);
            if (itv != st.end() && itv->first == v) union_set(a, itv->second);

            u = find_set(a);
            v = find_set(b);
            st.insert({u, v});
            st.insert({v, u});
        } else {
            if (u == v) cout << "SAFE" << endl;
            else if (st.find({u, v}) != st.end()) cout << "FATAL" << endl;
            else cout << "DUNNO" << endl;
        }
        // cout << "------------------" << endl;
        // cout << u << " " << v << endl;
        // for (auto mit : st) cout << "(" << mit.first << " " << mit.second << ") ";
        // cout << endl;
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
