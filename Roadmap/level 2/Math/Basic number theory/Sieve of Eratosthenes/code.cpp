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
    vector<bool> prime(n, true);
    prime[0] = prime[1] = 0;
    if (n >= 2) cout << 2 << " ";
    for(int i = 3; i <= n; i += 2) {
        if (!prime[i]) continue;
        cout << i << " ";
        if (i > sqrt(n)) continue;
        for(ll j = 1ll * i * i; j <= n; j += i) prime[j] = 0;
    } 
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
