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
const int MAXSIZE = 2e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() { 
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector<vi> tre(n + 1);
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    queue<int> q;
    vector<bool> visited(n + 1, 0);
    vector<int> dis1(n + 1, 0), disnnn(n + 1, 0);

    q.push(1);
    visited[1] = 1;
    while (q.size())
    {
        int top = q.front();
        q.pop();
        for (int i = 0; i < tre[top].size(); i++) {
            if (visited[tre[top][i]] == 0) {
                dis1[tre[top][i]] = dis1[top] + 1;
                visited[tre[top][i]] = 1;
                q.push(tre[top][i]);
            }
        }
    }
    int maxLe = INT_MAX, maxChan = INT_MAX;
    q.push(n);
    visited[n] = 0;
    while (q.size())
    {
        int top = q.front();
        q.pop();
        for (int i = 0; i < tre[top].size(); i++) {
            if (visited[tre[top][i]] == 1) {
                disnnn[tre[top][i]] = disnnn[top] + 1;
                int val = disnnn[tre[top][i]] + dis1[tre[top][i]];
                if (val % 2) maxLe = min(maxLe, val);
                else maxChan = min(maxChan, val);
                visited[tre[top][i]] = 0;
                q.push(tre[top][i]);
            }
        }
    }
    
    int ans = INT_MAX;
    auto checkFun = [&](int vall, int curr, int valrutt) -> void {
        if (vall == INT_MAX) return;
        if (valrutt == 0) ans = min(curr, ans); 
        else if (k % 2) {
            if (vall % 2 && vall <= k) ans = min(ans, 1);
            else if (vall % 2 == 0 && vall <= k) ans = min(ans, 2);    
            if (valrutt % 2) ans = min(curr + 1, ans);
            else ans = min(curr + 2, ans);
        } else {
            if (valrutt % 2) ans = min(ans, INT_MAX);
            if (vall <= k) ans = min(1, ans);
            else ans = min(curr + 1, ans);
        }
    };
    // cout << maxLe << maxChan << endl;
    checkFun(dis1[n], dis1[n] / k, dis1[n] % k);
    checkFun(maxLe, maxLe / k, maxLe % k);
    checkFun(maxChan, maxChan / k, maxChan % k);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; LLLLLLLLLLLLLLLLLLLLL
    while(t--){
        solve();
    }
    return 0;
}
