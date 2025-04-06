// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound  // find X < min(x)
#define lb lower_bound  // find X <= min(x)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 2e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vi> tree(n + 1);
    vector<bool> visited(n + 1, 0);
    vector<int> cal(n + 1, 0);

    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    cal[1] = (s[0] == '0') ? -1 : 1;
    int cnt = 0;

    while(q.size()) {
        int top = q.front();
        if (cal[top] < 0) cnt++;
        q.pop();
        for (int i = 0; i < (int)tree[top].size(); i++) {
            int idx = tree[top][i];
            if (!visited[idx]) {
                visited[idx] = 1;
                if (s[idx - 1] == '0') cal[idx] = cal[top] - 1;
                else cal[idx] = cal[top] + 1;
                q.push(idx);
            }
        }
    }

    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
