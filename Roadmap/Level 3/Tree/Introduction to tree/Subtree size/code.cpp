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

int subTree(vector<vi> &tree, vector<int>& cal, vector<bool>& visited, int v) {
    for (int i = 0; i < tree[v].size(); i++) {
        if (!visited[tree[v][i]]) {
            visited[tree[v][i]] = 1;
            cal[v] += subTree(tree, cal, visited, tree[v][i]);
        } 
    }
    return cal[v];
}

void solve() {    
    int n;
    cin >> n;
    vector<vi> tree(n + 1);
    vector<bool> visited(n + 1, 0);
    vector<int> cal(n + 1, 1);

    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = 1;
    cal[1] = subTree(tree, cal, visited, 1);
    
    FOR(i, 1, n + 1) cout << cal[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
