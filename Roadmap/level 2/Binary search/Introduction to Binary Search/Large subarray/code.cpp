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

void solve()
{
    int n; ll k;
    cin >> n >> k;
    int a;
    vector<ll> pref(n + 1);
    FOR(i, 0, n) cin >> a, pref[i + 1] = pref[i] + a;
    ll dem = 0;

    FOR(i, 1, n + 1) {
        dem += upper_bound(pref.begin(), pref.begin() + i, pref[i] - k) - pref.begin();
    }

    cout << dem << endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
