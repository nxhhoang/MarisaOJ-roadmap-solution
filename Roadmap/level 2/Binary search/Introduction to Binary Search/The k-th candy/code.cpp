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

    vector<pair<int, int>> aw(n);

    FOR(i, 0, n) cin >> aw[i].second >> aw[i].first;

    sort(all(aw));

    vector<ll> a(n + 1);

    FOR(i, 0, n) a[i + 1] = a[i] + aw[i].second;

    while(q--){
        ll k;
        cin >> k;

        cout << aw[lb(a.begin() + 1, a.end(), k) - a.begin() - 1].first << endl;
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
