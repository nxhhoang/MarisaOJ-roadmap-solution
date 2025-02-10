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
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    ll l, r;
    cin >> l >> r;
    vector<bool> disprime(r - l + 1, false);
    for (int i = 2; 1ll * i * i <= r; i++) {
        ll k = l;
        if (l % i) k = l / i * i + i;
        for (ll j = k; j <= r; j += i) if (j != i) disprime[j - l] = true;
    }
    for (ll i = 0; i <= r - l; i++) if (disprime[i] == 0 && i + l > 1) cout << i + l << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
