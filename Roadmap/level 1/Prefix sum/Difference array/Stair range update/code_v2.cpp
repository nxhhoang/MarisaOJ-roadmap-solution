#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

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

    vector<ll> D(n + 2);
    vector<int> last(n + 2);

    while(q--){
        int l, r;
        cin >> l >> r;
        D[l]++;
        D[r + 1]--;
        last[r + 1] += r - l + 1;
    }

    FOR(i, 1, n + 2) D[i] += D[i - 1], D[i - 1] -= last[i - 1];

    FOR(i, 1, n + 1) cout << (D[i] += D[i - 1]) << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
