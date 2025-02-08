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
 
ull overfl(int a, int b, int c) {
    int result = 1;
    a = a % c;
    
    while (b > 0) {
        if (b & 1) result = 1ll * result * a % c;
        a = 1ll * a * a % c;
        b >>= 1;
    }
 
    return result;
}

void solve() {
    string s;
    cin >> s;
    int mod = MOD + 2;
    vector<int> base(s.size() + 1, 331);
    vector<int> jash(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        jash[i + 1] = (jash[i] + 1ll * base[i] * s[i]) % mod;
        base[i + 1] = 1ll * base[i] * 331 % mod;
    }
    int i = 1;
    for (; i <= s.size(); i++) {
        int val = s.size() / i;
        int league = val * i;
        int nhan = overfl(base[i - 1] + mod - 1, mod - 2, mod);
        int sum = ((1ll * jash[i] * (base[league - 1] + mod - 1)) % mod) * nhan % mod;
        sum = (sum + 1ll * base[league - 1] * jash[(int)s.size() - league]) % mod;
        if (sum == jash[s.size()]) break;
    }

    cout << s.substr(0, i);
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
