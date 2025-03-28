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

string vec[502];
bool vis[502][502] = {0};

void solve() {
    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) cin >> vec[i];

    int ans = 0;
    FOR(i, 0, n) FOR(j, 0, m){
        if (vis[i][j] || vec[i][j] != 'W') continue;
        queue<int> q;
        int cham = 0;
        int dem = 1;
        q.push(i * m + j);
        vis[i][j] = 1;
        while(q.size()){
            int x = q.front() / m;
            int y = q.front() % m;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int a = x + dx[k];
                int b = y + dy[k];
                if (a < 0 || a >= n || b < 0 || b >= m || vec[a][b] == 'B') continue;
                if (vec[a][b] == '.') {
                    cham++;
                    continue;
                }
                if (vis[a][b]) continue;
                dem++;
                vis[a][b] = 1;
                q.push(a * m + b);
            }
        }
        if (!cham) ans += dem;
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
