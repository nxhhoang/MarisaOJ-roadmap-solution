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

int maxDepth(vector<vi> &tree, vector<bool> &visited, vector<int> &cal, int v, int& maxV) {
	int L1st = -1;
	int L2nd = -1;
	int idx1 = -1;
	int idx2 = -1;
	for (int i = 0; i < tree[v].size(); i++) {
        if (visited[tree[v][i]] == 0) {
            visited[tree[v][i]] = 1;
            int VAL = maxDepth(tree, visited, cal, tree[v][i], maxV);
            cal[v] = max(cal[v], VAL);
            if (VAL >= L1st)
            {
                idx2 = idx1;
                L2nd = L1st;
                L1st = VAL;
                idx1 = i;
            }
            else if (idx1 != i && L1st >= VAL && VAL >= L2nd) idx2 = i, L2nd = VAL;
        }
    }
	if (L1st != -1 && L2nd != -1) maxV = max(maxV, L1st + L2nd);
    return ++cal[v];
}

void solve() {    
    int n;
    cin >> n;
    vector<vi> tree(n + 1);
    vector<bool> visited(n + 1, 0);
    vector<int> cal(n + 1, 0);

    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int dinh = 1;
    for (int i = 1; i <= n; i++) {
        if (tree[i].size() >= 2) {
            dinh = i;
            break;
        }
    }
    visited[dinh] = 1;

    int large1st = 0;
    int large2nd = 0;
	int maxV = INT_MIN;
    for (int i = 0; i < tree[dinh].size(); i++) {
        visited[tree[dinh][i]] = 1;
        cal[tree[dinh][i]] = maxDepth(tree, visited, cal, tree[dinh][i], maxV);
        if (cal[large1st] < cal[tree[dinh][i]]) large1st = tree[dinh][i];
    }
    for (int i = 0; i < tree[dinh].size(); i++) {
        if (tree[dinh][i] != large1st 
            && cal[tree[dinh][i]] <= cal[large1st] 
            && cal[large2nd] <= cal[tree[dinh][i]]) large2nd = tree[dinh][i];
    }

    cout << max(cal[large1st] + cal[large2nd], maxV) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
