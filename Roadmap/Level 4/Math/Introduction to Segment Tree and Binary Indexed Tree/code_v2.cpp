// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound  // find X < min(x)
#define lb lower_bound  // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 2e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

class SegmentTree{
private:
    vector<ll> tree;
    void build(int idx, int l, int r) {
        if (l == r) {
            cin >> tree[idx]; 
            return;
        }

        int mid = l + r >> 1;
        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
public:
    SegmentTree(int n){
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, int l, int r, int i, int val) {
        if (l > i || r < i) return;

        if (l == r) {
            tree[idx] = val;
            return;
        }

        int mid = l + r >> 1;
        update(2 * idx + 1, l, mid, i, val);
        update(2 * idx + 2, mid + 1, r, i, val);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    ll query(int idx, int l, int r, int x, int y){
        if (r < x || y < l) return 0;
        
        if (l >= x && r <= y) return tree[idx];

        int mid = l + r >> 1;
        return query(2 * idx + 1, l, mid, x, y) + query(2 * idx + 2, mid + 1, r, x, y);
    }
};

void solve() { 
    int n, q;
    cin >> n >> q;
    SegmentTree seg = SegmentTree(n);

    while (q--){
        int d, i, x;
        cin >> d >> i >> x;
        if (d == 1) seg.update(0, 0, n - 1, i - 1, x);
        else cout << seg.query(0, 0, n - 1, i - 1, x - 1) << endl; 
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
