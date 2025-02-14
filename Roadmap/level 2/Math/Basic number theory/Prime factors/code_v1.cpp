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
const int MAXN = 1e6;
const int MOD = 1e9 + 7;

void solve() {
    vector<bool> prime(MAXN + 1, true);
    vector<int> pri;
    pri.push_back(2); 

    for (int i = 3; i <= MAXN; i += 2) { 
        if (!prime[i]) continue;
        pri.push_back(i);
        if (i > 1000) continue; 
        for (ll j = 1ll * i * i; j <= MAXN; j += i) prime[j] = 0;
    }

    int q;
    cin >> q; 

    while (q--) {
        int n;
        cin >> n;

        for (int i = 0; i < pri.size() && pri[i] * pri[i] <= n; i++) {
            if (n % pri[i]) continue; 
            while (n % pri[i] == 0) { 
                n /= pri[i];
            }
            cout << pri[i] << " ";
        }
        if (n > 1) cout << n;

        cout << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
