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
    int n, cnt0[32] = {0}, cnt1[32] = {0}, a, j;
    cin >> n;
    ll cnt = 0, so0 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        j = 0;
        if (a) {  
            while(a) {
                if ((a & 1) == 0) cnt0[j]++;
                j++;
                a >>= 1;
            }
            cnt += cnt1[j - 1]++;
        } else so0++;
    }
    cnt *= 2;

    for (int i = 0; i < 32; i++) cnt += 2ll * cnt1[i] * cnt0[i];
    ll ans = 1ll * n * n - cnt - n;
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
