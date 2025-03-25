// nxhhoang - the dreamer
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

vector<bool> vis(MAXSIZE, 0);

void solve() {
    int n, m;
    cin >> n >> m;
 
    queue<pair<ll, ll>> q;
    q.push({n, 0});
    while(q.size()) {
        auto [val, ans] = q.front();
        q.pop();
        ll x, y;
        x = val * 2;
        y = val - 1;
        if (x == m || y == m) {
            cout << ans + 1 << endl;
            return;
        }
        if (x >= 1 && x <= 200000 && vis[x] == 0) q.push({x, ans + 1}), vis[x] = 1;
        if (y >= 1 && y <= 200000 && vis[y] == 0) q.push({y, ans + 1}), vis[y] = 1;
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
