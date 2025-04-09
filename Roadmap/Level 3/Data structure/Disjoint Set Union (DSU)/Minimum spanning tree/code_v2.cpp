// nxhhoang - the dreamer
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
const int NN = 1000 + 3;
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 3;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class DSU {
private:
    int vec[MAXSIZE]; //, st[MAXSIZE];
public:
    DSU(int n) {
        for (int i = 1; i <= n; i++) make_set(i);  
    }
    void make_set(int u) {
        vec[u] = u;
        // st[u] = 1;
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
            // st[b] += st[a];
        }
    }
    
    bool check(int u, int v) {
        return find_set(u) == find_set(v);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    DSU dsu = DSU(n);
    multimap<int, pii> mp;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        mp.insert({c, {a, b}});
    }
    ll sum = 0;
    int cnt = 0;
    for (auto it : mp) {
        if (cnt == n - 1) {
            cout << sum;
            return;
        }
        if (dsu.check(it.second.first, it.second.second) == 0) {
            sum += it.first;
            cnt++;
            dsu.union_set(it.second.first, it.second.second);
        } 
    }
    cout << sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
