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

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt0(32, 0);
    vector<int> cnt1(32, 0);

    int a, j;
    ll cnt = 0;
    ll so0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        j = 0;
        if (a) {  
            int val = 31 - __builtin_clz(a);
            cnt1[val]++;
            while(a) {
                if ((a & 1) == 0) cnt0[j]++;
                j++;
                a >>= 1;
            }
        } else so0++;
    }
    // cnt -= so0;
    // for (int i = 0; i < 32; i++) {
    //     cout << cnt0[i] << "  " << cnt1[i] << endl;
    // }

    for (int i = 0; i < 32; i++) cnt += 2ll * cnt0[i] * cnt1[i] + 1ll * cnt1[i] * (cnt1[i] - 1);
    // cout << cnt << endl;
    ll ans = 1ll * n * n - cnt - n;
    // cout << ans << endl;
    ans = ans / 2 + so0 * (so0 + 1) / 2; // a >= b loai b <= a
    cout << ans;
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
