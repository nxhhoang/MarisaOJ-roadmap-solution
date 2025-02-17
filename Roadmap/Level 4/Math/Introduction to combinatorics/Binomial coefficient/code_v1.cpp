// nxxhoang - the dreamer
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

ull overfl(int a, int b, int c) {
    int result = 1;
    a = a % c;
    
    while (b > 0) {
        if (b & 1) result = 1ll * result * a % c;
        a = 1ll * a * a % c;
        b >>= 1;
    }
 
    return result;
}

int fac[MAXN];
int dao[MAXN];
void solve() {
    int q;
    cin >> q;
    fac[0] = dao[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = 1ll * i * fac[i - 1] % MOD;
        dao[i] = overfl(fac[i], MOD - 2, MOD);
    }
    while(q--){
        int n, k;
        cin >> n >> k;
        int val = (1ll * fac[n] * dao[k] % MOD) * 1ll * dao[n - k] % MOD;
        cout << val << endl;
    }
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
