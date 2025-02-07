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

void solve() {
    string s, c;
    cin >> s >> c;
    ll base = 331;
    ll mod = MOD + 2;
    ll cur = 1;
    ll val = 0;
    int cnt = 0;

    vector<ll> preF(s.size() + 1, 0);

    for (int i = 0; i < s.size(); i++) {
        preF[i + 1] = (preF[i] + base * s[i]) % mod;
        if (i < c.size()) val = (val + base * c[i]) % mod;
        if (i >= c.size() - 1) {
            ll sum = val * cur % mod;
            ll prod = (preF[i + 1] - preF[i - c.size() + 1] + mod) % mod;
            if (sum == prod) cnt++;
            cur = cur * 331 % mod;
        }
        base = base * 331 % mod;
    }

    cout << cnt;
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
