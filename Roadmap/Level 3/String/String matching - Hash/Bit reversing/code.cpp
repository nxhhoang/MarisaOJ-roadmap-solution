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

const ll inf = 2e18;
const int NN = 10;
const int MSIZE = 1e5 + 5;
const int MAXN = 3e5 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> mat(n);
    vector<vi> arr(n + 1, vi(m + 1));
    for (int i = 0; i < n; i++) cin >> mat[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i + 1][j + 1] = mat[i][j] - '0';
        }
    }

    vector<vi> pre(n + 1, vi(m + 1));
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            pre[i][j] = arr[i][j] ^ arr[i - 1][j] ^ arr[i][j - 1] ^ arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c || b == d) {
            cout << "YES" << endl;
        } else {
            int sum = pre[c][d] - pre[c][b] - pre[a][d] + pre[a][b];
            
            if (sum == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
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
