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
    vector<int> prime(MAXN + 1, 0);
    prime[2] = 2;
    for (ll j = 4; j <= MAXN; j += 2) prime[j] = 2;
 
    for (int i = 3; i <= MAXN; i += 2) { 
        if (prime[i]) continue; 
        prime[i] = i;
        for (ll j = 1ll * i * i; j <= MAXN; j += i) if (!prime[j]) prime[j] = i;
    }
 
    int q;
    cin >> q;
 
    while (q--) {
        int n;
        cin >> n;
 
        while(n > 1){
            int p = prime[n];
            cout << p << " ";
            while (n % p == 0) n /= p;
        }
 
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
