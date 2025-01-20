#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    vector<vector<int>> matrix(MAXSIZE);
    FOR(i, 0, n) cin >> A[i], matrix[A[i]].push_back(i);

    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;

        auto ll = lb(matrix[x].begin(), matrix[x].end(), l);
        auto rr = ub(matrix[x].begin(), matrix[x].end(), r);

        if (ll == matrix[x].end() || *ll > r) cout << 0 << endl;
        else cout << rr - ll << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
