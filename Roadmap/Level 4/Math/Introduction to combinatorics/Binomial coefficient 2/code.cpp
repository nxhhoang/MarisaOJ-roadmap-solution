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
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ull overfl(ll a, ll b) {
    ll result = 1;
    
    while (b > 0) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
 
    return result;
}

void solve()
{
    int q;
    cin >> q;
    vector<int> fac(101, 1);
    vector<int> unfac(101, 1);

    for (int i = 2; i < 101; i++) 
        fac[i] = 1ll * i * fac[i - 1] % MOD;
    unfac[100] = overfl(fac[100], MOD - 2);
    for (int i = 100; i >= 1; i--) 
        unfac[i - 1] = 1ll * i * unfac[i] % MOD;

    while (q--) {
        int n, k;
        cin >> n >> k;
        ll val = 1;
        for (int i = n - k + 1; i <= n; i++) {
            val = val * i % MOD;
        }
        cout << (val * unfac[k]) % MOD << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
