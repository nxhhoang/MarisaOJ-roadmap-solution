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

vector<ll> res(MAXN, 0);

ll eque(ll val) {
    if (val < MAXN) return res[val];
    return max(val, eque(val/2) + eque(val/3) + eque(val/4));
}

void solve()
{
    int T, x;
    cin >> T;
    res[0] = 0;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i < MAXN; i++) {
        res[i] = max(1ll * i, res[i / 2] + res[i / 3] + res[i / 4]);
    }
    while (T--) {
        cin >> x;
        if (x < MAXN) cout << res[x] << endl;
        else cout << eque(x) << endl;
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
