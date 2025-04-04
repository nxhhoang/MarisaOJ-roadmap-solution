// nxhhoang - the dreamer
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
    int n, k;
    cin >> n >> k;
    vector<vi> tree(n + 1);
    vector<int> visited(n + 1, 0);

    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int cnt_left = 0;

    while(q.size()) {
        int v = q.front();
        q.pop();
        bool flag = 1;
        for (int i = 0; i < tree[v].size(); i++){
            if (visited[tree[v][i]] == 0) {
                q.push(tree[v][i]);
                flag = 0;
                visited[tree[v][i]] = visited[v] + 1;
            }
        }
        if (flag) cnt_left++;
    }
    sort(visited.begin() + 2, visited.end(), greater<int>());
    ll sum = 0;

    FOR(i, 2, k + 2) sum += visited[i] - 1; 

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
