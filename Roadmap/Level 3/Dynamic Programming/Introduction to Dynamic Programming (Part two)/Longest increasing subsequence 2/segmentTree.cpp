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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};


class SegmentTree
{
private:
    vector<int> tree;

public:
    SegmentTree(int n)
    {
        tree.resize(4 * n, 0);
    }

    void update(int idx, int l, int r, int x, int y, int val)
    {
        if (y < l || r < x)
            return;

        if (l >= x && r <= y)
        {
            tree[idx] = val;
            return;
        }

        int mid = l + r >> 1;
        update(2 * idx + 1, l, mid, x, y, val);
        update(2 * idx + 2, mid + 1, r, x, y, val);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int x, int y)
    {
        if (r < x || y < l)
            return 0;

        if (l >= x && r <= y)
            return tree[idx];

        int mid = l + r >> 1;
        return max(query(2 * idx + 1, l, mid, x, y), query(2 * idx + 2, mid + 1, r, x, y));
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i];
    }
    sort(all(brr));
    brr.erase(unique(all(brr)), brr.end());

    SegmentTree seg(brr.size());
    int r = brr.size();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(brr), arr[i]);
        int ggg = seg.query(0, 0, r - 1, 0, it - brr.begin());
        int val = 1;
        if (it != brr.begin()) {
            --it;
            val += seg.query(0, 0, r - 1, 0, it - brr.begin());
            ++it;
        } 
        if (val > ggg) seg.update(0, 0, r - 1, it - brr.begin(), it - brr.begin(), val);
    }
    cout << seg.query(0, 0, r - 1, 0, r - 1);
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
