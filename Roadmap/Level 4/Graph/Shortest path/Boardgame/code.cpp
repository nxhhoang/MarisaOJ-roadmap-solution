// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe

// __builtin_popcount(x); - leftmost bit
// __builtin_parity(x); nums of 1 (even or odd)
// __builtin_ctz(x); count trailing zeros
// __builtin_clz(x); count leading zeros

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second
#define SIZE(x) (int)(x).size()

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MSIZE = 1e5 + 5;
const int MAXN = 5e6 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

ll n, L, R, X, u, v;
vector<int> arr(MSIZE);
vector<int> a_b(MSIZE);
vector<vi> cnt(MSIZE);

vector<ll> dp(MSIZE, LLONG_MAX / 1000);
vector<ll> maxV(MSIZE, LLONG_MAX / 1000);
priority_queue<pll, vector<pll>, greater<pll>> pq;

void solve()
{
    cin >> n >> L >> R >> X >> u >> v;
    vector<pii> brr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i], brr[i].first = arr[i], brr[i].second = i;

    sort(1 + all(brr));

    int ver = 1;
    int sosa = brr[1].first;
    for (int i = 1; i <= n; i++) {
        if (sosa != brr[i].first) ver++, sosa = brr[i].first;
        a_b[brr[i].second] = ver;
        cnt[ver].push_back(brr[i].second);
    }

    dp[u] = 0;
    pq.push({0, u});

    while (SIZE(pq)) {
        auto [pa, ve] = pq.top();
        pq.pop();

        if (pa > dp[ve]) continue;

        if (ve >= 2) {
            int TO = ve - 1;
            if (dp[TO] > pa + L) {
                dp[TO] = pa + L;
                pq.push({dp[TO], TO});
            }
        }

        if (ve <= n - 1) {
            int TO = ve + 1;
            if (dp[TO] > pa + R) {
                dp[TO] = pa + R;
                pq.push({dp[TO], TO});
            }
        }

        if (maxV[a_b[ve]] <= pa) continue; 
        maxV[a_b[ve]] = pa;

        for (auto pos : cnt[a_b[ve]]) {
            if (dp[pos] > pa + X) {
                dp[pos] = pa + X;
                
                if (pos >= 2) {
                    int TO = pos - 1;
                    if (dp[TO] > pa + X + L) {
                        dp[TO] = pa + X + L;
                        pq.push({dp[TO], TO});
                    }
                }

                if (pos <= n - 1) {
                    int TO = pos + 1;
                    if (dp[TO] > pa + X + R) {
                        dp[TO] = pa + X + R;
                        pq.push({dp[TO], TO});
                    }
                }
            }
        }
    }

    cout << dp[v] << endl;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout)
    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

    while (t--)
    {
        solve();
    }
    return 0;
}
