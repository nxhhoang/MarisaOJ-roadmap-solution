// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<pair<int, int>>
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


int n, q, S, T;
inline ll calc(ll x) {
    if (x < 0) return 1ll * x * T;
    return 1ll * x * S; 
}

void solve()
{
    cin >> n >> q >> S >> T;
    vector<int> vec(n + 1);
    FOR(i, 0, n + 1) cin >> vec[i];
    vector<ll> diff(n + 2, 0);
    ll sum = 0;
    FOR(i, 0, n) {
        diff[i + 1] = vec[i + 1] - vec[i];
        sum += calc(diff[i + 1]);
    }
    

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        sum -= calc(diff[l]);
        if (r + 1 < n + 1) sum -= calc(diff[r + 1]);
        diff[l] += x;
        diff[r + 1] -= x;
        sum += calc(diff[l]);
        if (r + 1 < n + 1) sum += calc(diff[r + 1]);
        cout << -sum << endl;
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
