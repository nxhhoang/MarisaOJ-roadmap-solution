// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
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
const int MSIZE = 1e5 + 5;
const int MAXN = 2e5 + 1;
const int MOD = 1e9 + 7;
// const int dx[] = {1, -1, 0, 0};
// const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};


int n;
vector<vector<vi>> mat(101, vector<vi>(101, vector<int>(101)));
vector<vector<vector<ll>>> dp(101, vector<vector<ll>>(101, vector<ll>(101, INT_MAX)));

void solve()
{   
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> mat[i][j][k];
            }
        }
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    int dbr = n * n;
    pq.push({0, 0});
    dp[0][0][0] = 0;
    while (pq.size()) {
        auto [pa, ve] = pq.top();
        pq.pop();
        int i = ve / dbr;
        int j = (ve % dbr) / n;
        int k = (ve % n);
        // cout << pa << " " << i << " " << j << " " << k << endl;

        if (dp[i][j][k] < pa) continue;
        // dp[i][j][k]
        
        for (int x = 0; x < 6; x++) {
            int a = i + dx[x];
            int b = j + dy[x];
            int c = k + dz[x];

            if (a < 0 || b < 0 || c < 0 || a >= n || b >= n || c >= n) continue;
            if (dp[a][b][c] > pa + mat[a][b][c]) {
                dp[a][b][c] = pa + mat[a][b][c];
                pq.push({dp[a][b][c], a * dbr + b * n + c});
            }
        }
        
    }
    cout << dp[n - 1][n - 1][n - 1];
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
