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
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n, m, k, a, u, v;
    cin >> n >>  m >> k;
    vector<int> A(n + 1, 0);
    vector<vi> tre(n + 1);
    vector<int> dis(n + 1, 0);
    FOR(i, 0, k) cin >> a, A[a]++;
    FOR(i, 0, m) {
        cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }

    queue<int> q;
    vector<int> visited(n + 1, 0);
    q.push(n);
    visited[n] = 1;
    dis[n] = 0;
    while(q.size()){
        int top = q.front();
        q.pop();
        visited[top] = 1;
        for (int i = 0; i < tre[top].size(); i++){
            if (visited[tre[top][i]] == 0) {
                dis[tre[top][i]] = dis[top] + 1;
                visited[tre[top][i]] = 1;
                q.push(tre[top][i]);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i < n + 1; i++) {
        // cout << dis[i] << endl;
        if (A[i] && dis[i] <= dis[1]) cnt += A[i]; //&& (dis[0] - dis[i]) % 2 == 0) cnt++; 
    }
    cout << cnt;
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
