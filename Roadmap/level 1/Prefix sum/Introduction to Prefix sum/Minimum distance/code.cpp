#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    ll pre = 0;
    ll sum = 0;

    FOR(i, 0, n) {
        cin >> ar[i];
        if (i < n / 2) pre -= ar[i];
            else pre += ar[i];
        sum += 1ll * min(i, n - i) * ar[i];
    }
    if (n % 2) pre -= ar[n / 2];

    ll ans = sum;
    FOR(i, 0, n) {
        pre += 2 * ar[i];
        if (n % 2) pre -= ar[(n / 2 + i) % n] + ar[(n / 2 + i + 1) % n];
        else pre -= 2 * ar[(n / 2 + i) % n];
        sum += pre;
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
