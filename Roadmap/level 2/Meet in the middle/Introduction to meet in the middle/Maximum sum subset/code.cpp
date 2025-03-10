// nxxhoang - the dreamer
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define endl '\n'
#define ub upper_bound // find X < min(x)
#define lb lower_bound // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

vector<int> vt(40);
vector<ll> cur, fin;

const int mod = 1e9;

void backtrack(ll sum, int i, int size, vector<ll>& cu) {
    if (i >= size) {
        cu.push_back(sum % mod);
        return;
    }

    backtrack(sum, i + 1, size, cu);
    backtrack(sum + vt[i], i + 1, size, cu);
}

void solve()
{
    int n;
    cin >> n;
    FOR (i, 0, n) cin >> vt[i];

    backtrack(0, 0, n >> 1, cur);
    backtrack(0, n >> 1, n, fin);

    sort(all(fin));
    ll ans = 0;
    FOR (i, 0, cur.size()) {
        auto it = upper_bound(all(fin), mod - cur[i]);
        if (it != fin.begin()) --it;
        ans = max(ans, (cur[i] + *it) % mod);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
