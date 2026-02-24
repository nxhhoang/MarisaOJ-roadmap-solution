// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
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

void solve()
{
    int n, arr;
    cin >> n ;
    int mod = 123456789;
    vector<int> pos(MAXN, -1);
    vector<int> pref(n + 1, 0);
    vector<int> dp(n + 1, 0);
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
		cin >> arr;
        if (pos[arr] == -1) dp[i] = (pref[i - 1] + 1) % mod;
        else dp[i] = (pref[i - 1] - pref[pos[arr] - 1] + mod) % mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
        pos[arr] = i;
    }
    cout << pref[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    while (t--)
    {
        solve();
    }
    return 0;
}
