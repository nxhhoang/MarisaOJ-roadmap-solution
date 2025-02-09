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
    string s;
    cin >> s;
    int n = s.size();
    int mod = MOD + 2;
    vector<int> base(n + 1, 331);
    vector<int> jash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        jash[i + 1] = (jash[i] + 1ll * base[i] * s[i]) % mod;
        base[i + 1] = 1ll * base[i] * 331 % mod;
    }
    for (int i = 1; i <= n; i++) {
        int lea = n / i * i; 
        bool flag = 1;
        for (int j = i; j <= n - i; j += i) {
            if (1ll * jash[i] * base[j - 1] % mod != (jash[j + i] - jash[j] + mod) % mod) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) continue;
        if ((1ll * base[lea - 1] * jash[n - lea]) % mod 
                == (jash[n] - jash[lea] + mod) % mod) {
            cout << s.substr(0, i);
            return;                    
        }
    }

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
