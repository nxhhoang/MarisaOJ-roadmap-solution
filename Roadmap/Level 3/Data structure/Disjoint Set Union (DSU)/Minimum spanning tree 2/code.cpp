// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
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
const int MSIZE = 1e5 + 5;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class DSU {
public:
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
            if (st[a] > st[b])
                swap(a, b);
            vec[a] = b;
            st[b] += st[a];
        }
    }

    bool check(int u, int v) {
        return find_set(u) == find_set(v);
    }
};

struct forth
{
    int fi;
    int se;
    int th;
    int fo;

    bool operator==(const forth &m) const {
        return fi == m.fi && se == m.se && th == m.th && fo == m.fo;
    }
};

int n, m;
vector<vector<pii>> tre(MSIZE);
vector<forth> ed;
vector<bool> val(MSIZE);
DSU sml, bg;
forth pre;

void init()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tre[a].push_back({b, w});
        tre[b].push_back({a, w});
        ed.push_back({w, a, b, i});
    }
    for (int i = 1; i <= n; i++) {
        sml.make_set(i);
        bg.make_set(i);
    }
}

void solve()
{
    init();

    sort(all(ed), [](const forth &a, const forth &b) -> bool
         { return a.fi < b.fi 
            || (a.fi == b.fi && a.se < b.se) 
            || (a.fi == b.fi && a.se == b.se && a.th < b.th) 
            || (a.fi == b.fi && a.se == b.se && a.th == b.th && a.fo < b.fo); });

    pre = {ed[0].fi, ed[0].se, ed[0].th, ed[0].fo};
    val[ed[0].fo] = 1;
    bg.union_set(ed[0].se, ed[0].th);
    int j = 0;

    for (int i = 1; i < m; i++) {
        int fi = ed[i].fi;
        int se = ed[i].se;
        int th = ed[i].th;
        int fo = ed[i].fo;

        int pfi = pre.fi;
        int pse = pre.se;
        int pth = pre.th;
        int pfo = pre.fo;

        if (ed[i] == pre) {
            val[fo] = val[pfo];
            continue;
        }

        if (bg.check(se, th)) {
            if (fi > pfi) continue;
            
            if (sml.check(se, th)) continue;
            // cout << "--- " ;
        } 
        // cout << se << " " << th << "  " << j << "  " << i << endl;

        val[fo] = 1;
        

        if (fi != pfi) {
            for (; j < i; j++) {
                if (val[ed[j].fo]) sml.union_set(ed[j].se, ed[j].th);
            }
        }
        pre = ed[i];
        bg.union_set(se, th);
    }

    for (int i = 0; i < m; i++)
        cout << val[i];
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
