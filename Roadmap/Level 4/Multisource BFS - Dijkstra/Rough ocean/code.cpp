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
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve()
{
    int n, r;
    cin >> n >> r;
    vector<string> ma(n);
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++) cin >> ma[i];

    queue<int> q;
    queue<int> goc;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ma[i][j] == 'X') q.push(i * n + j), goc.push(i * n + j), visited[i][j] = 1;
        }
    }

    while (q.size()) {
        int t = q.front();
        int x = t / n, y = t % n;
        q.pop();
        int tt = goc.front();
        int i = tt / n, j = tt % n;
        goc.pop();
        if (abs(x - i) + abs(y - j) <= r) cnt++;
        else continue;

        for (int k = 0; k < 4; k++) {
            int a = x + dx[k];
            int b = y + dy[k];
            if (a < 0 || b < 0 
                    || a >= n || b >= n 
                    || visited[a][b]) continue;
            visited[a][b] = 1;
            q.push(a * n + b);
            goc.push(i * n + j);
        }
    }
    cout << 1ll * n * n - cnt;
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
