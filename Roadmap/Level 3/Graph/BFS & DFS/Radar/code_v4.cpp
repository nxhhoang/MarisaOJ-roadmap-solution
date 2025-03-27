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

ll dist[1004][1004];

void solve()
{
    int n;
    cin >> n;
    vector<pii> vec(n + 1);
    FOR(i, 1, n + 1) cin >> vec[i].first >> vec[i].second;

    double l = 0, r = INT_MAX;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            dist[i][j] = (1ll * (vec[j].first - vec[i].first) * (vec[j].first - vec[i].first) + 
                                1ll * (vec[j].second - vec[i].second) * (vec[j].second - vec[i].second));
    while(r - l > 1e-7) {
        double R = (r + l) / 2;
        long double RR = (2 * R) * (2 * R);
        vector<bool> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        bool flag = 1;
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int i = 1; i < n + 1; i++){
                if (vis[i]) continue;
                if (RR > dist[i][x]) {
                    q.push(i);
                    vis[i] = 1;
                }      
            }
        }
        for (int i = 1; i < n + 1; i++) if (vis[i] == 0) flag = 0;
        if (flag) r = R; 
        else l = R;
    }
    cout << fixed <<setprecision(6) << l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
