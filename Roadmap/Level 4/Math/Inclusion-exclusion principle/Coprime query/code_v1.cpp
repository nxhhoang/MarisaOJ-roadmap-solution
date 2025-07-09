// nxhhoang - the dreamer
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

ll n, q;
ll pri[21];
int l = 0;
vector<pair<ll, int>> mes;
void backtrack(int cnt, ll dov, int i) {
    if (i >= l) {
        mes.push_back({dov, cnt});
        return;
    }

    backtrack(cnt, dov, i + 1);
    if (1e12 / pri[i] >= dov) backtrack(cnt + 1, dov * pri[i], i + 1);
}

void solve()
{
    cin >> n >> q;
    int k = 0;
    vector<int> primes(MAXN, 0);
    for (int i = 2; i < MAXN; i++) {
        if (primes[i] == 0) {
            primes[k++] = i;
            for (ll j = 1ll * i * i; j < MAXN; j += i) primes[j] = 1;
        }
    }

    for (int i = 0; i < k && 1ll * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            pri[l++] = primes[i];
            while (n % primes[i] == 0) {
                n /= primes[i];
            }
        }
    }

    if (n > 1) pri[l++] = n;

    sort(pri, pri + l, greater<int>());
    backtrack(0, 1, 0);
    
    while (q--) {
        ll L, R;
        cin >> L >> R;
        L--;
        ll sum = 0;
        for (int i = 1; i < mes.size(); i++){
            if (mes[i].second % 2) sum += (R / mes[i].first - L / mes[i].first); 
            else sum -= (R / mes[i].first - L / mes[i].first);
        }
        cout << (R - L) - sum << endl;
    } 
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
