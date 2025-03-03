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
#define ull unsigned long long
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

ll overflow(ll a, ll b, ll c) {
    ll result = 0;

    while (b > 0) {
        if (b & 1) result = (result + a) % c;
        a = 2 * a % c;
        b >>= 1;
    }

    return result;
}

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << overflow(a, b, c) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
