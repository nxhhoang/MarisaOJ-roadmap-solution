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


int vec[MSIZE], st[MSIZE];

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
    int n, q;
    set<pii> ab;

    cin >> n >> q;

    
    for (int i = 0; i <= n; i++) make_set(i);
    for (int i = 1; i <= q; i++) {
        int l, r, t;
        cin >> l >> r >> t;

        if (l > r) {
            cout << i - 1 << endl;
            return;
        }

        int u = find_set(l - 1);
        int v = find_set(r);

        if (t == 0) {
            if (ab.find({u, v}) != ab.end()) {
                cout << i - 1 << endl;
                return;
            }

            int cnt = 0;
            auto it = ab.lb({u, 0});
            auto mit = ab.lb({v, 0});

            if (it != ab.end() && it->first == u) union_set(v, u), cnt++;
            if (mit != ab.end() 
                && mit->first == v 
                && it != mit 
                && it->first != mit->second && it->second != mit->first) {
                if (cnt == 0) union_set(u, v), cnt++;
                else {
                    if (find_set(mit->second) == find_set(u)) {
                        cout << i - 1 << endl;
                        return;
                    }
                    union_set(mit->second, it->second);
                    ab.erase(make_pair(mit->first, mit->second));
                    ab.erase(make_pair(mit->second, mit->first));
                }
            }

            if (cnt == 0) {
                if (st[u] > st[v]) swap(u, v); 
                union_set(u, v);
            }
        } else {
            if (u == v) {
                cout << i - 1 << endl;
                return;
            }
            
            int cnt = 0;
            auto it = ab.lb({u, 0});
            auto mit = ab.lb({v, 0});
            
            if (it != ab.end() && it->first == u) union_set(v, it->second), cnt++;
            if (mit != ab.end() 
                && mit->first == v 
                && it != mit
                && it->first != mit->second && it->second != mit->first) {
                if (cnt == 0) union_set(u, mit->second), cnt++;
                else {
                    if (find_set(mit->second) == find_set(it->second)) {
                        cout << i - 1 << endl;
                        return;
                    }
                    union_set(mit->second, u);
                    ab.erase({mit->first, mit->second});
                    ab.erase({mit->second, mit->first});
                }
            }
        
            if (cnt == 0) {
                ab.insert({u, v}); 
                ab.insert({v, u});
            }
        }
        // for (auto ve : ab) cout << "-(" << ve.first << ", " << ve.second << ")- ";
        // cout << endl; 
        // cout << SIZE(ab) << endl;
    }
    cout << q << endl;
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
