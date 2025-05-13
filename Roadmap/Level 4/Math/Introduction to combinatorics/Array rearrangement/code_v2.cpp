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

ull overfl(ll a, ll b) {
    ll result = 1;
    
    while (b > 0) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
 
    return result;
}

ll fac[MAXN];
ll dao[MAXN];
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(i, 0, n) cin >> arr[i];
    sort(all(arr));
    
    fac[0] = dao[0] = 1;
    for (int i = 1; i < MAXN; i++) fac[i] = i * fac[i - 1] % MOD;
    dao[MAXN - 1] = overfl(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i >= 1; i--) dao[i - 1] = dao[i] * i % MOD;

    ll sum = fac[n];
    int val = arr[0];
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (val == arr[i]) dem++;
        else {
            sum = (sum * dao[dem]) % MOD;
            val = arr[i];
            dem = 1;
        }
    }
    sum = (sum * dao[dem]) % MOD;

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
