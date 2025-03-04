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
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

ll overfl(ll a, ll b) {
    ll result = 1;
    
    while (b > 0) {
        if (b & 1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return result % MOD;
}

void solve()
{
    ll n;
    cin >> n;
    ll result = overfl(36, n / 3);
    if (n % 3 == 1) result = result * 3 % MOD;
    else if (n % 3 == 2) result = result * 9 % MOD;

    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
