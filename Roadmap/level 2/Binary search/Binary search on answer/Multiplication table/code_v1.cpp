// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll n, m, k;

ll calc(ll x, ll &maxV, ll &range) {
    ll cnt = 0;
    ll sos = min(x, m * 1ll);
    for (ll i = 1; i <= n; i++) {
        ll val = x / (1ll * i);
        if (x % i == 0 && val <= sos) range++;
        ll minV = min(val, 1ll * m);
        maxV = max(maxV, 1ll * i * minV);
        cnt += minV;
    }
    return cnt;
}

void solve()
{
    cin >> n >> m >> k;
    ll l = 1;
    ll r = 1ll * n * m;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll maxV = 0;
        ll range = 0;
        ll cnt = calc(mid, maxV, range);
        if (k <= cnt && k > cnt - range){
            cout << maxV;
            return;    
        } 
        else if (cnt > k) r = mid;
        else l = mid + 1;
    }
    cout << "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
