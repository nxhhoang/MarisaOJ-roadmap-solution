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
const int MAXN = 1e6 + 3;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ull overfl(ll a, ll b) {
    ll result = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
 
    return result;
}
void solve() { 
    vector<int> fac(MAXSIZE);
    vector<int> un_fac(MAXSIZE); // x1 + x2 + x3 = 8 
    int n, k, p; cin >> n >> k;
    fac[0] = fac[1] = 1;
    for (int i = 1; i < MAXSIZE; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    un_fac[MAXSIZE - 1] = overfl(fac[MAXSIZE - 1], MOD - 2);        
    for (int i = MAXSIZE - 1; i >= 1; i--) un_fac[i - 1] = 1ll * un_fac[i] * i % MOD; 
    map<int, int> arr;
    for (int i = 0; i < n; i++) cin >> p, arr[p]++;
    int dem = 0;
    ll res = 0;
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        dem += it->second;
        int cur = n - dem;
        if (cur + it->second < k) break;
        for (int j = max(1, k - cur); j <= min(it->second, k); j++) {
            ll val1 = (1ll * fac[it->second] * un_fac[j] % MOD) * un_fac[it->second - j] % MOD;
            ll val2 = (1ll * fac[cur] * un_fac[k - j] % MOD) * un_fac[cur - k + j] % MOD;
            res += (1ll * val1 * val2 % MOD) * it->first % MOD;
        }
    }
    cout << res % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; LLLLLLLLLLLLLLLLLLLLL
    while(t--){
        solve();
    }
    return 0;
}
