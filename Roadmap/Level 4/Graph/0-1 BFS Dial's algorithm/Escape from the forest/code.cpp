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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct tu {
    ll val;
    int x, y;
    int type;
};

struct cmp {
    bool operator()(tu a, tu b) {
        return a.val < b.val;
    } 
};

const int mov[][4] = {
    {0, 1, -1, 1}, // down  // 0
    {1, -1, 1, 0}, // left  // 1
    {-1, 1, 0, 1}, // up    // 2
    {1, 0, 1, -1}  // right // 3
};

const int nexT[][4] = {
    {0, 3, -1, 1},
    {0, -1, 2, 1},
    {-1, 3, 2, 1},
    {0, 3, 2, -1}
};

int n;
vector<string> mat(2001);
vector<vector<vi>> dp(2001, vector<vi>(2001, vi(4, INT_MAX / 100)));
deque<tu> pq;

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++) cin >> mat[i];

    pq.push_front(tu{0, 0, 0, 0});
    dp[0][0][0] = 0;
    
    while (SIZE(pq)) {
        auto [val, x, y, type] = pq.front();
        pq.pop_front();

        if (dp[x][y][type] < val) continue;
        
        for (int i = 0; i < 4; i++) {
            if (mov[type][i] == -1) continue;
            int a = x + dx[i];
            int b = y + dy[i];
            int next_type = nexT[type][i];
            int cost = mov[type][i];

            if (a < 0 || b < 0 || a >= n || b >= n || mat[a][b] == '#') continue;

            if (dp[a][b][next_type] > val + cost) {
                dp[a][b][next_type] = val + cost;
                
                if (cost == 0) pq.push_front({dp[a][b][next_type], a, b, next_type});
                else pq.push_back({dp[a][b][next_type], a, b, next_type});
            }
        }
    }

    ll minV = min({dp[n - 1][n - 1][0], dp[n - 1][n - 1][1], dp[n - 1][n - 1][2], dp[n - 1][n - 1][3]});
    if (minV >= INT_MAX / 100) cout << -1 << endl;
    else cout << minV << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout);

    int t = 1;
    // cin >> t; // DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

    while (t--)
    {
        solve();
    }
    return 0;
}
